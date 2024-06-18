/*
** EPITECH PROJECT, 2024
** B-OOP-400-NCE-4-1-raytracer-steven.deffontaine [WSL : Ubuntu]
** File description:
** Ray
*/

#include "../Vec3/Vec3.hpp"

#ifndef RAY_HPP_
    #define RAY_HPP_

    class Ray {
        public:
            Ray();
            ~Ray() = default;

            Ray(const Vec3 &origin, const Vec3 &direction);
            Ray(const Vec3 &origin, const Vec3 &direction, double time)
            : orig(origin), dir(direction), _time(time) {}
            const Vec3 &origin() const;
            const Vec3 &direction() const;
            double time() const { return _time; }
            Vec3 point_at_parameter(float t) const;
        protected:
        private:
            Point3 orig;
            Vec3 dir;
            double _time;
    };

#endif /* !RAY_HPP_ */
