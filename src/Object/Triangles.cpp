/*
** EPITECH PROJECT, 2024
** raytracer [WSL: Ubuntu]
** File description:
** Triangle
*/

#include "Triangles.hpp"

Vec3 Triangle::normalize(const Vec3 &v) const {
    float length = sqrt(v.x() * v.x() + v.y() * v.y() + v.z() * v.z());
    return Vec3(v.x() / length, v.y() / length, v.z() / length);
}

bool Triangle::hit(const Ray &r, float t_min, float t_max, hit_record &rec) const {
    Vec3 edge1 = _v1 - _v0;
    Vec3 edge2 = _v2 - _v0;

    Vec3 h = cross(r.direction(), edge2);
    float a = dot(edge1, h);

    if (a > -EPSILON && a < EPSILON)
        return false;

    float f = 1.0 / a;
    Vec3 s = r.origin() - _v0;
    float u = f * dot(s, h);

    if (u < 0.0 || u > 1.0)
        return false;

    Vec3 q = cross(s, edge1);
    float v = f * dot(r.direction(), q);

    if (v < 0.0 || u + v > 1.0)
        return false;

    float t = f * dot(edge2, q);

    if (t > EPSILON && t >= t_min && t <= t_max) {
        rec.t = t;
        rec.p = r.point_at_parameter(rec.t);
        rec.normal = normalize(cross(edge1, edge2));
        rec.mat_ptr = mat_ptr;
        return true;
    }

    return false;
}
