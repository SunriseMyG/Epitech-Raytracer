/*
** EPITECH PROJECT, 2024
** raytracer [WSL: Ubuntu]
** File description:
** Planes
*/

#include "Planes.hpp"

bool Planes::hit(const Ray &r, float t_min, float t_max, hit_record &rec) const
{
    float t = (_center.z() - r.origin().z()) / r.direction().z();
    if (t < t_min || t > t_max)
        return false;
    
    float x = r.origin().x() + t * r.direction().x();
    float y = r.origin().y() + t * r.direction().y();
    
    float half_length = _length / 2.0;
    float half_width = _width / 2.0;
    
    if (x < (_center.x() - half_length) || x > (_center.x() + half_length) || 
        y < (_center.y() - half_width) || y > (_center.y() + half_width))
        return false;
    
    rec.t = t;
    rec.p = r.point_at_parameter(t);
    rec.normal = Vec3(0, 0, 1);
    rec.mat_ptr = mat_ptr;
    return true;
}
