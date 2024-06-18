/*
** EPITECH PROJECT, 2024
** raytracer [WSL: Ubuntu]
** File description:
** Triangle
*/

#include "../UtilsObject/Ray/Ray.hpp"
#include "../UtilsObject/Hitable/Hitable.hpp"


#ifndef TRIANGLE_HPP_
    #define TRIANGLE_HPP_

    class Materials;

    class Triangle : public Hitable {
        public:
            Triangle() = default;
            Triangle(Vec3 v0, Vec3 v1, Vec3 v2, Materials *m) : _v0(v0), _v1(v1), _v2(v2), mat_ptr(m) {}
            virtual ~Triangle() = default;

            virtual Vec3 normalize(const Vec3 &v) const;
            virtual bool hit(const Ray &r, float t_min, float t_max, hit_record &rec) const override;
        private:
            Vec3 _v0, _v1, _v2;
            Materials *mat_ptr;
            const float EPSILON = 1e-9;
    }; 

#endif /* !TRIANGLE_HPP_ */
