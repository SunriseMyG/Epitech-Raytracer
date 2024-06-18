/*
** EPITECH PROJECT, 2024
** B-OOP-400-NCE-4-1-raytracer-steven.deffontaine [WSL : Ubuntu]
** File description:
** Hitable
*/

#include "../Ray/Ray.hpp"

#ifndef HITABLE_HPP_
    #define HITABLE_HPP_

    class Materials;

    struct hit_record {
        float t;
        Vec3 p;
        Vec3 normal;
        Materials *mat_ptr;
        double u;
        double v;
    };

    class Hitable {
        public:
            Hitable() = default;
            ~Hitable() = default;

            virtual bool hit(const Ray &r, float t_min, float t_max, hit_record &rec) const = 0;
        protected:
        private:
    };

#endif /* !HITABLE_HPP_ */
