/*
** EPITECH PROJECT, 2024
** B-OOP-400-NCE-4-1-raytracer-steven.deffontaine
** File description:
** Cone
*/

#include "Cone.hpp"

bool Cone::hit(const Ray &r, float t_min, float t_max, hit_record &rec) const {
    Vec3 oc = r.origin() - _center;

    float k = _radius / _height;
    k *= k;

    float a = r.direction().x() * r.direction().x() + r.direction().z() * r.direction().z() - k * r.direction().y() * r.direction().y();
    float b = 2.0f * (oc.x() * r.direction().x() + oc.z() * r.direction().z() - k * oc.y() * r.direction().y());
    float c = oc.x() * oc.x() + oc.z() * oc.z() - k * oc.y() * oc.y();

    float discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        float root = sqrt(discriminant);
        for (int sign : {-1, 1}) {
            float temp = (-b + sign * root) / (2 * a);
            if (temp < t_max && temp > t_min) {
                Vec3 p = r.point_at_parameter(temp);
                float y = p.y() - _center.y();
                if (y >= -_height && y <= _height) {
                    rec.t = temp;
                    rec.p = p;
                    float nx = (p.x() - _center.x()) / _radius;
                    float ny = (k * _height / _radius);
                    float nz = (p.z() - _center.z()) / _radius;
                    float length = sqrt(nx * nx + ny * ny + nz * nz);
                    rec.normal = Vec3(nx / length, ny / length, nz / length);

                    rec.mat_ptr = _mat_ptr;
                    return true;
                }
            }
        }
    }
    return false;
}
