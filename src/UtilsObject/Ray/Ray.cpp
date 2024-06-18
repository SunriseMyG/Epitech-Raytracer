/*
** EPITECH PROJECT, 2024
** B-OOP-400-NCE-4-1-raytracer-steven.deffontaine [WSL : Ubuntu]
** File description:
** Ray
*/

#include "Ray.hpp"

Ray::Ray()
{
}

Ray::Ray(const Point3 &origin, const Vec3 &direction)
    : orig(origin), dir(direction)
{
}

const Vec3 &Ray::origin() const
{
    return orig;
}

const Vec3 &Ray::direction() const
{
    return dir;
}

Vec3 Ray::point_at_parameter(float t) const
{
    return orig + t * dir;
}
