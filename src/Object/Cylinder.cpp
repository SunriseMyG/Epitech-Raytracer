/*
** EPITECH PROJECT, 2024
** B-OOP-400-NCE-4-1-raytracer-steven.deffontaine [WSL: Ubuntu]
** File description:
** cylindre
*/

#include "Cylinder.hpp"

bool Cylinder::hit(const Ray &r, float t_min, float t_max, hit_record &rec) const {
    Vec3 oc = r.origin() - _center;

    float a = r.direction().x() * r.direction().x() + r.direction().z() * r.direction().z();
    float b = 2.0f * (oc.x() * r.direction().x() + oc.z() * r.direction().z());
    float c = oc.x() * oc.x() + oc.z() * oc.z() - _radius * _radius;

    float discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        float root = sqrt(discriminant);
        for (int sign : {-1, 1}) {
            float temp = (-b + sign * root) / (2 * a);
            if (temp < t_max && temp > t_min) {
                Vec3 p = r.point_at_parameter(temp);
                float y = p.y() - _center.y();
                if (y >= -_height / 2 && y <= _height / 2) {
                    rec.t = temp;
                    rec.p = p;
                    rec.normal = Vec3((rec.p.x() - _center.x()) / _radius, 0, (rec.p.z() - _center.z()) / _radius);
                    rec.mat_ptr = _mat_ptr;
                    return true;
                }
            }
        }
    }
    return false;
}
