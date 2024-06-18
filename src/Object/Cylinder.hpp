/*
** EPITECH PROJECT, 2024
** B-OOP-400-NCE-4-1-raytracer-steven.deffontaine [WSL: Ubuntu]
** File description:
** cylindre
*/

#include "../UtilsObject/Ray/Ray.hpp"
#include "../UtilsObject/Hitable/Hitable.hpp"

#ifndef CYLINDER_HPP_
#define CYLINDER_HPP_

class Cylinder : public Hitable {
    public:
        Cylinder() = default;
        ~Cylinder() = default;

        Cylinder(Vec3 center, float radius, float height, Materials *m) : _center(center), _radius(radius), _height(height), _mat_ptr(m) {};
        bool hit(const Ray &r, float t_min, float t_max, hit_record &rec) const override;
    protected:
            Vec3 _center;
            float _radius;
            float _height;
            Materials *_mat_ptr;

private:
};

#endif /* CYLINDER_HPP_ */