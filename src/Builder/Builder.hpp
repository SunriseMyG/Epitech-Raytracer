/*
** EPITECH PROJECT, 2024
** raytracer [WSL: Ubuntu]
** File description:
** Builder
*/

#include "../UtilsObject/Vec3/Vec3.hpp"
#include "../UtilsObject/Hitable/Hitable.hpp"
#include "../Textures/Textures.hpp"
#include "../UtilsObject/Materials/Materials.hpp"

#include "../Object/Sphere.hpp"
#include "../Object/Cylinder.hpp"
#include "../Object/Planes.hpp"
#include "../Object/Cone.hpp"
#include "../Object/Triangles.hpp"

#ifndef BUILDER_HPP_
    #define BUILDER_HPP_

    class Builder {
        public:
            Builder();
            ~Builder() = default;
            Builder& setType(std::string type);
            Builder& setCenter(Vec3 center);
            Builder& setRadius(float radius);
            Builder& setHeight(float height);
            Builder& setLength(float length);
            Builder& setWidth(float width);
            Builder& setColor(Vec3 color);
            Builder& setPoint1(Vec3 point1);
            Builder& setPoint2(Vec3 point2);
            Builder& setPoint3(Vec3 point3);
            Builder& setTexturePatch(std::string type);
            Builder& setTexture(std::string type);
            Builder& setMaterial(std::string type);
            Hitable *buildObject();

            void reset();

        protected:
            Vec3 _center;
            std::string _type;
            float _radius;
            float _height;
            float _length;
            float _width;
            Vec3 _point1;
            Vec3 _point2;
            Vec3 _point3;
            Vec3 _color;
            std::string _texturePatch;
            std::shared_ptr<Textures> _texture;
            Materials *_material;
    };

#endif /* !BUILDER_HPP_ */
