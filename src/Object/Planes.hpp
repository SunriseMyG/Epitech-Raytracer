/*
** EPITECH PROJECT, 2024
** raytracer [WSL: Ubuntu]
** File description:
** Planes
*/

#ifndef PLANES_HPP_
#define PLANES_HPP_

    #include "../UtilsObject/Ray/Ray.hpp"
    #include "../UtilsObject/Hitable/Hitable.hpp"


    class Materials;

    class Planes : public Hitable {
        public:
            Planes() = default;
            ~Planes() = default;

            Planes(Vec3 center, float length, float width, float height, Materials *m) : _center(center), _length(length), _width(width), _height(height), mat_ptr(m) {};
            virtual bool hit(const Ray &r, float t_min, float t_max, hit_record &rec) const override;
        protected:
            Vec3 _center;
            float _length;
            float _width;
            float _height;
            Materials *mat_ptr;
        private:
    };

#endif /* !PLANES_HPP_ */
