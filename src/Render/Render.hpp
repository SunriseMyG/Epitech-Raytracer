/*
** EPITECH PROJECT, 2024
** raytracer [WSL: Ubuntu]
** File description:
** Render
*/

#include "IRender.hpp"

#ifndef RENDER_HPP_
    #define RENDER_HPP_

    class Render {
        public:
            Render() = default;
            ~Render() = default;
            void RenderImage(Parsing &parsing, std::string filename);
            Vec3 RayColor(const Ray &r, Hitable *world, int depth);

            Vec3 Background;
    };

#endif /* !RENDER_HPP_ */
