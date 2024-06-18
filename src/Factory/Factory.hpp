/*
** EPITECH PROJECT, 2024
** raytracer [WSL: Ubuntu]
** File description:
** Factory
*/

#include "../UtilsObject/Vec3/Vec3.hpp"
#include "../UtilsObject/Hitable/Hitable.hpp"
#include "../Textures/Textures.hpp"
#include "../UtilsObject/Materials/Materials.hpp"

#include "../Object/Sphere.hpp"

#ifndef FACTORY_HPP_
    #define FACTORY_HPP_

    class Factory {
        public:
            Factory();
            ~Factory() = default;
            Hitable *createLight(Vec3 center, float intensity, Vec3 color = Vec3(1, 1, 1));
    };

#endif /* !FACTORY_HPP_ */
