/*
** EPITECH PROJECT, 2024
** B-OOP-400-NCE-4-1-raytracer-steven.deffontaine [WSL : Ubuntu]
** File description:
** Textures
*/

#include "Textures.hpp"

Vec3 Checker_texture::Value(float u, float v, const Vec3 &p) const
{
    auto xInteger = int(std::floor(inv_scale * p.x()));
    auto yInteger = int(std::floor(inv_scale * p.y()));
    auto zInteger = int(std::floor(inv_scale * p.z()));

    bool isEven = (xInteger + yInteger + zInteger) % 2 == 0;

    return isEven ? even->Value(u, v, p) : odd->Value(u, v, p);
}

Vec3 Image_texture::Value(float u, float v, const Vec3 &p) const
{
    (void)p;
    if (_image.heights() <= 0)
        return Vec3(0, 1, 1);
    u = Interval(0, 1).clamp(u);
    v = 1.0 - Interval(0, 1).clamp(v);

    auto i = int(u * _image.widths());
    auto j = int(v * _image.heights());
    auto pixel = _image.pixel_data(i, j);

    auto color_scale = 1.0 / 255.0;
    return Vec3(color_scale * pixel[0], color_scale * pixel[1], color_scale * pixel[2]);
}
