/*
** EPITECH PROJECT, 2024
** B-OOP-400-NCE-4-1-raytracer-steven.deffontaine [WSL : Ubuntu]
** File description:
** Color
*/

#include "../Vec3/Vec3.hpp"
#include <iostream>

using color = Vec3;

#ifndef COLOR_HPP_
    #define COLOR_HPP_

    class Color {
        public:
            Color() = default;
            ~Color() = default;
            Color(int r, int g, int b) : r(r), g(g), b(b) {};
            Vec3 RGBtoVec3();
            void write_color(std::ostream &out, color pixel_color);

        protected:
        private:
            int r;
            int g;
            int b;
    };

#endif /* !COLOR_HPP_ */
