/*
** EPITECH PROJECT, 2024
** raytracer [WSL: Ubuntu]
** File description:
** Parsing
*/

#include "Parsing.hpp"

void Parsing::help()
{
    std::cout << "USAGE: ./raytracer <SCENE_FILE>" << std::endl;
    std::cout << "\tSCENE_FILE: scene configuration" << std::endl;
}

void Parsing::checkArgs(int ac, char **av)
{
    try {
        if (ac != 2)
            throw ErrorsParsing("Invalid number of arguments");
    } catch (ErrorsParsing &e) {
        std::cerr << e.what() << std::endl;
        exit(84);
    }

    if (std::string(av[1]).compare("--help") == 0) {
        help();
        exit(0);
    }

    try {
        if (std::string(av[1]).find(".cfg") == std::string::npos)
            throw ErrorsParsing("Invalid file extension");
    } catch (ErrorsParsing &e) {
        std::cerr << e.what() << std::endl;
        exit(84);
    }
}

void Parsing::loadData()
{
    //camera
    lookUpValue("camera.resolution.width", _camera.resolution.width);
    lookUpValue("camera.resolution.height", _camera.resolution.height);
    lookUpValue("camera.position.x", _camera.position.x);
    lookUpValue("camera.position.y", _camera.position.y);
    lookUpValue("camera.position.z", _camera.position.z);
    lookUpValue("camera.rotation.x", _camera.rotation.x);
    lookUpValue("camera.rotation.y", _camera.rotation.y);
    lookUpValue("camera.rotation.z", _camera.rotation.z);
    lookUpValue("camera.fieldOfView", _camera.fov);
    lookUpValue("camera.depthOfField", _camera.dof);
    lookUpValue("camera.quality", _camera.quality);

    //light
    lookUpValue("lights.skycolor.r", _light.skycolor.r);
    lookUpValue("lights.skycolor.g", _light.skycolor.g);
    lookUpValue("lights.skycolor.b", _light.skycolor.b);
    libconfig::Setting &lightsPoint = lookUp("lights.point");

    for (int i = 0; i < lightsPoint.getLength(); i++) {
        libconfig::Setting &point = lightsPoint[i];
        struct light::position pos;
        pos.x = point["x"];
        pos.y = point["y"];
        pos.z = point["z"];
        _light.positions.push_back(pos);
    }

    //Primitive

    libconfig::Setting &objects = lookUp("primitives");
    std::cout << "Primitve:" << std::endl;

    Builder builder;

    int num_objects = objects.getLength() + lightsPoint.getLength();

    Hitable **list = new Hitable*[num_objects];

    int i = 0;

    for (i = 0; i < objects.getLength(); i++) {
        libconfig::Setting &object = objects[i];
        std::string type = object["type"];
        printf("\ttype: %s\n", type.c_str());
        Vec3 pos(0, 0, 0);
        lookUpValue("primitives.[" + std::to_string(i) + "].x", pos[0]);
        lookUpValue("primitives.[" + std::to_string(i) + "].y", pos[1]);
        lookUpValue("primitives.[" + std::to_string(i) + "].z", pos[2]);
        int r, g, b;
        lookUpValue("primitives.[" + std::to_string(i) + "].color.r", r);
        lookUpValue("primitives.[" + std::to_string(i) + "].color.g", g);
        lookUpValue("primitives.[" + std::to_string(i) + "].color.b", b); 

        Color color(r, g, b);
        Vec3 colorVec = color.RGBtoVec3(); 
    
        std::cout << "\tnumber: "<< i << std::endl;
        std::cout << "\ttype:" << std::endl;
        std::cout << "\t\t" << type << std::endl;
        std::cout << "\tposition:" << std::endl;
        std::cout << "\t\tx: " << pos[0] << std::endl;
        std::cout << "\t\ty: " << pos[1] << std::endl;
        std::cout << "\t\tz: " << pos[2] << std::endl;
        std::cout << "\tcolor:" << std::endl;
        std::cout << "\t\tr: " <<   colorVec[0] << std::endl;
        std::cout << "\t\tg: " <<   colorVec[1] << std::endl;
        std::cout << "\t\tb: " <<   colorVec[2] << std::endl;

        float radius = 0.0;
        float height = 0.0;
        float length = 0.0;
        float width = 0.0;
        Vec3 point1(0, 0, 0);
        Vec3 point2(0, 0, 0);
        Vec3 point3(0, 0, 0);
        std::string texturePatch = "";
        std::string texture = "unknown";
        std::string material = "lambertian";

        lookUpValue("primitives.[" + std::to_string(i) + "].radius", radius);
        lookUpValue("primitives.[" + std::to_string(i) + "].height", height);
        lookUpValue("primitives.[" + std::to_string(i) + "].length", length);
        lookUpValue("primitives.[" + std::to_string(i) + "].width", width);
        lookUpValue("primitives.[" + std::to_string(i) + "].texturePatch", texturePatch);
        lookUpValue("primitives.[" + std::to_string(i) + "].texture", texture);
        lookUpValue("primitives.[" + std::to_string(i) + "].material", material);

        lookUpValue("primitives.[" + std::to_string(i) + "].point1.x", point1[0]);
        lookUpValue("primitives.[" + std::to_string(i) + "].point1.y", point1[1]);
        lookUpValue("primitives.[" + std::to_string(i) + "].point1.z", point1[2]);

        lookUpValue("primitives.[" + std::to_string(i) + "].point2.x", point2[0]);
        lookUpValue("primitives.[" + std::to_string(i) + "].point2.y", point2[1]);
        lookUpValue("primitives.[" + std::to_string(i) + "].point2.z", point2[2]);

        lookUpValue("primitives.[" + std::to_string(i) + "].point3.x", point3[0]);
        lookUpValue("primitives.[" + std::to_string(i) + "].point3.y", point3[1]);
        lookUpValue("primitives.[" + std::to_string(i) + "].point3.z", point3[2]);

        list[i] = builder
                        .setType(type)
                        .setCenter(pos)
                        .setRadius(radius)
                        .setHeight(height)
                        .setLength(length)
                        .setWidth(width)
                        .setPoint1(point1)
                        .setPoint2(point2)
                        .setPoint3(point3)
                        .setColor(colorVec)
                        .setTexturePatch(texturePatch)
                        .setTexture(texture)
                        .setMaterial(material)
                        .buildObject();

        builder.reset();
    }

    printf("\tObjects created: %d\n", num_objects);

    Factory factory;

    for (int j = 0; j < lightsPoint.getLength(); j++) {
        Vec3 pos(0, 0, 0);
        lookUpValue("lights.point.[" + std::to_string(j) + "].x", pos[0]);
        lookUpValue("lights.point.[" + std::to_string(j) + "].y", pos[1]);
        lookUpValue("lights.point.[" + std::to_string(j) + "].z", pos[2]);
        int r, g, b = 255;
        lookUpValue("lights.point.[" + std::to_string(j) + "].color.r", r); 
        lookUpValue("lights.point.[" + std::to_string(j) + "].color.g", g);
        lookUpValue("lights.point.[" + std::to_string(j) + "].color.b", b);
        Color color(r, g, b);
        Vec3 colorVec = color.RGBtoVec3();
        float intensity = 1.0;
        lookUpValue("lights.point.[" + std::to_string(j) + "].intensity", intensity);

        list[i++] = factory.createLight(pos, intensity, colorVec);
    }

    printf("\tLights created: %d\n", lightsPoint.getLength());

    _world = new Hitable_list(list, num_objects);
}

void Parsing::dumpData()
{
    std::cout << "Camera:" << std::endl;
    std::cout << "\tcamera.resolution.width: " << _camera.resolution.width << std::endl;
    std::cout << "\tcamera.resolution.height: " << _camera.resolution.height << std::endl;
    std::cout << "\tcamera.position.x: " << _camera.position.x << std::endl;
    std::cout << "\tcamera.position.y: " << _camera.position.y << std::endl;
    std::cout << "\tcamera.position.z: " << _camera.position.z << std::endl;
    std::cout << "\tcamera.rotation.x: " << _camera.rotation.x << std::endl;
    std::cout << "\tcamera.rotation.y: " << _camera.rotation.y << std::endl;
    std::cout << "\tcamera.rotation.z: " << _camera.rotation.z << std::endl;
    std::cout << "\tcamera.fov: " << _camera.fov << std::endl;
    std::cout << "\tcamera.dof: " << _camera.dof << std::endl;

    std::cout << "Light:" << std::endl;
    if (_light.positions.size() > 0)
        std::cout << "\tlight.positions:" << std::endl;
    for (size_t i = 0; i < _light.positions.size(); i++) {
        std::cout << "\t\tlight.position[" << i << "].x: " << _light.positions[i].x << std::endl;
        std::cout << "\t\tlight.position[" << i << "].y: " << _light.positions[i].y << std::endl;
        std::cout << "\t\tlight.position[" << i << "].z: " << _light.positions[i].z << std::endl;
    }
}

void Parsing::parseFile(const std::string &file)
{
    _libConfig.setFile(file);
    _libConfig.openFile();
}

libconfig::Setting &Parsing::lookUp(const std::string &path)
{
    return _libConfig.lookUp(path);
}

void Parsing::lookUpValue(const std::string &path, int &value)
{
    _libConfig.lookUpValue(path, value);
}

void Parsing::lookUpValue(const std::string &path, std::string &value)
{
    _libConfig.lookUpValue(path, value);
}

void Parsing::lookUpValue(const std::string &path, float &value)
{
    _libConfig.lookUpValue(path, value);
}
