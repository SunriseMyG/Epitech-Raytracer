/*
** EPITECH PROJECT, 2024
** B-OOP-400-NCE-4-1-raytracer-steven.deffontaine [WSL : Ubuntu]
** File description:
** Color
*/

#include "Color.hpp"

void Color::write_color(std::ostream &out, color pixel_color)
{
    out << static_cast<int>(255.999 * pixel_color[0]) << ' '
        << static_cast<int>(255.999 * pixel_color[1]) << ' '
        << static_cast<int>(255.999 * pixel_color[2]) << '\n';
}

Vec3 Color::RGBtoVec3()
{
    int r = this->r/255;
    int g = this->g/255;
    int b = this->b/255;
    return Vec3(r, g, b);
}
