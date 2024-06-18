/*
** EPITECH PROJECT, 2024
** raytracer [WSL: Ubuntu]
** File description:
** IRender
*/

#ifndef IRENDER_HPP_
    #define IRENDER_HPP_

    #include "../CreatePPM/CreatePPM.hpp"
    #include "../Object/Sphere.hpp"
    #include "../Object/Cylinder.hpp"
    #include "../Object/Planes.hpp"
    #include "../Object/Cone.hpp"
    #include "../UtilsObject/Vec3/Vec3.hpp"
    #include "../UtilsObject/Color/Color.hpp"
    #include "../UtilsObject/Ray/Ray.hpp"
    #include "../UtilsObject/Hitable/Hitable_list.hpp"
    #include "../Camera/Camera.hpp"
    #include "../Parsing/Parsing.hpp"
    #include "../UtilsObject/Materials/Materials.hpp"
    #include "../Textures/Textures.hpp"
    #include "../Factory/Factory.hpp"
    #include "../Sfml/Graphics.hpp"
    #include <thread>
    #include <mutex>
    #include <signal.h>
    #include <atomic>
    #include "../Observer/Observer.hpp"


    class IRender {
        public:
            IRender() = default;
            ~IRender() = default;

            virtual void RenderImage(Parsing &parsing, std::string filename) = 0;
            virtual Vec3 RayColor(const Ray &r, Hitable *world, int depth) = 0;
    };

#endif /* !IRENDER_HPP_ */
