/*
** EPITECH PROJECT, 2024
** B-OOP-400-NCE-4-1-raytracer-steven.deffontaine
** File description:
** Sphere
*/

#include "../UtilsObject/Ray/Ray.hpp"
#include "../UtilsObject/Hitable/Hitable.hpp"

#ifndef SPHERE_HPP_
    #define SPHERE_HPP_

    class Materials;

    class Sphere : public Hitable {
        public:
            Sphere() = default;
            ~Sphere() = default;

            Sphere(Vec3 center, float radius, Materials *m) : _center(center), _radius(radius), mat_ptr(m) {};
            virtual bool hit(const Ray &r, float t_min, float t_max, hit_record &rec) const override;
            static Vec3 random_in_unit_sphere();
        protected:
            Vec3 _center;
            float _radius;
            Materials *mat_ptr;
        private:
    };

#endif /* !SPHERE_HPP_ */
