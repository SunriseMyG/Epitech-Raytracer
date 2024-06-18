/*
** EPITECH PROJECT, 2024
** raytracer [WSL: Ubuntu]
** File description:
** Builder
*/

#include "Builder.hpp"

Builder::Builder()
{
    _type = "";
    _center = Vec3(0, 0, 0);
    _radius = 0;
    _height = 0;
    _length = 0;
    _width = 0;
    _color = Vec3(0, 0, 0);
    _point1 = Vec3(0, 0, 0);
    _point2 = Vec3(0, 0, 0);
    _point3 = Vec3(0, 0, 0);
    _material = nullptr;
    _texturePatch = "";
    _texture = nullptr;
}

Builder& Builder::setType(std::string type)
{
    _type = type;
    return *this;
}

Builder& Builder::setCenter(Vec3 center)
{
    _center = center;
    return *this;
}

Builder& Builder::setRadius(float radius)
{
    _radius = radius;
    return *this;
}

Builder& Builder::setHeight(float height)
{
    _height = height;
    return *this;
}

Builder& Builder::setLength(float length)
{
    _length = length;
    return *this;
}

Builder& Builder::setWidth(float width)
{
    _width = width;
    return *this;
}

Builder& Builder::setColor(Vec3 color)
{
    _color = color;
    return *this;
}

Builder& Builder::setTexturePatch(std::string type)
{
    _texturePatch = type;
    return *this;
}

Builder& Builder::setPoint1(Vec3 point1)
{
    _point1 = point1;
    return *this;
}

Builder& Builder::setPoint2(Vec3 point2)
{
    _point2 = point2;
    return *this;
}

Builder& Builder::setPoint3(Vec3 point3)
{
    _point3 = point3;
    return *this;
}

Builder& Builder::setTexture(std::string type)
{
    if (type == "color" || type == "solid" || type == "Solid" || type == "Color") {
        _texture = std::make_shared<Solid_color>(_color);
    } else if (type == "chess" || type == "Chess") {
        _texture = std::make_shared<Checker_texture>(0.32, Vec3(.2, .3, .1), Vec3(0.9, 0.9, 0.9));
    } else if (type == "image" || type == "Image"  || type == "img" || type == "Img") {
        _texture = std::make_shared<Image_texture>(_texturePatch.c_str());
    } else {
        _texture = std::make_shared<Checker_texture>(0.75, Vec3(1.0, .02, 1.0), Vec3(0.0, 0.0, 0.0));
    }
    return *this;
}

Builder& Builder::setMaterial(std::string type)
{
    if (type == "lambertian" || type == "Lambertian") {
        _material = new Lambertian(_texture);
    } else if (type == "metal" || type == "Metal") {
        _material = new Metal(Vec3(0.1,0.2,0.5), 0.5);
    } else if (type == "dielectric" || type == "Dielectric") {
        _material = new Dielectric(1.5);
    } else if (type == "light" || type == "Light") {
        _material = new Diffuse_Light(_texture);
    } else {
        _material = new Lambertian(_texture);
    }
    return *this;
}

void Builder::reset()
{
    _type = "";
    _center = Vec3(0, 0, 0);
    _radius = 0;
    _height = 0;
    _length = 0;
    _width = 0;
    _color = Vec3(0, 0, 0);
    _point1 = Vec3(0, 0, 0);
    _point2 = Vec3(0, 0, 0);
    _point3 = Vec3(0, 0, 0);
    _material = nullptr;
    _texturePatch = "";
    _texture = nullptr;
}

Hitable *Builder::buildObject()
{
    if (_type == "sphere" || _type == "sp" || _type == "Sp" || _type == "Sphere") {
        return new Sphere(_center, _radius, _material);
    } else if (_type == "cylinder" || _type == "cy" || _type == "Cy" || _type == "Cylinder") {
        return new Cylinder(_center, _radius, _height, _material);
    } else if (_type == "planes" || _type == "pl" || _type == "Pl" || _type == "Planes") {
        return new Planes(_center, _length, _width, _height, _material);
    } else if (_type == "cone" || _type == "co" || _type == "Co" || _type == "Cone") {
        return new Cone(_center, _radius, _height, _material);
    } else if (_type == "triangles" || _type == "tr" || _type == "Tr" || _type == "Triangles") {
        return new Triangle(_point1, _point2, _point3, _material);
    } else {
        return new Sphere(Vec3(.0 , .0, .0), 0.0, _material);
    }
    return nullptr;
}