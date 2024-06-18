/*
** EPITECH PROJECT, 2024
** B-OOP-400-NCE-4-1-raytracer-steven.deffontaine [WSL : Ubuntu]
** File description:
** Vec3
*/

#include <iostream>
#include <math.h>
#include <cmath>

#ifndef VEC3_HPP_
    #define VEC3_HPP_

    class Vec3 {
        public:
            Vec3() = default;
            ~Vec3() = default;

            Vec3(float e0, float e1, float e2);
            float x() const;
            float y() const;
            float z() const;
            
            float r() const;
            float g() const;
            float b() const;

            inline const Vec3 &operator+() const;
            Vec3 operator-() const;
            float operator[](int i) const;
            float& operator[](int i);

            Vec3& operator+=(const Vec3 &v);
            Vec3& operator-=(const Vec3 &v);
            Vec3& operator*=(const Vec3 &v);
            Vec3& operator/=(const Vec3 &v);
            Vec3& operator*=(const float t);
            Vec3& operator/=(const double t);
    
            float length() const;
            float length_squared() const;

            Vec3& normalize();

            bool near_zero() const;

            float random_double();
            float random_double(float min, float max);

            Vec3 random();
            Vec3 random(float min, float max);

            

            float e[3];

        protected:
        private:
    };

    using Point3 = Vec3;

    std::ostream &operator<<(std::ostream &out, const Vec3 &v);
    std::istream &operator>>(std::istream &in, Vec3 &v);
    Vec3 operator+(const Vec3 &u, const Vec3 &v);
    Vec3 operator-(const Vec3 &u, const Vec3 &v);
    Vec3 operator*(const Vec3 &u, const Vec3 &v);
    Vec3 operator*(float t, const Vec3 &v);
    Vec3 operator*(const Vec3 &v, float t);
    Vec3 operator/(Vec3 v, float t);
    double dot(const Vec3 &u, const Vec3 &v);
    Vec3 cross(const Vec3 &u, const Vec3 &v);
    Vec3 unit_vector(Vec3 v);
    Vec3 reflect(const Vec3 &v, const Vec3 &n);
    bool refract(const Vec3 &uv, const Vec3 &n, float etai_over_etat, Vec3 &refracted);
    float schlick(float cosine, float ref_idx);

#endif /* !VEC3_HPP_ */
