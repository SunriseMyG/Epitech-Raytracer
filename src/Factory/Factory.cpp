/*
** EPITECH PROJECT, 2024
** B-OOP-400-NCE-4-1-raytracer-steven.deffontaine
** File description:
** Factory
*/

#include "Factory.hpp"

Factory::Factory()
{
}

Hitable *Factory::createLight(Vec3 center, float intensity, Vec3 color)
{
    return new Sphere(center, intensity, new Diffuse_Light(color));
}
