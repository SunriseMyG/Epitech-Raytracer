/*
** EPITECH PROJECT, 2024
** B-OOP-400-NCE-4-1-raytracer-steven.deffontaine [WSL : Ubuntu]
** File description:
** Vec3
*/

#include "Vec3.hpp"

Vec3::Vec3(float e0, float e1, float e2)
{
    e[0] = e0;
    e[1] = e1;
    e[2] = e2;
}

float Vec3::x() const
{
    return e[0];
}

float Vec3::y() const
{
    return e[1];
}

float Vec3::z() const
{
    return e[2];
}

float Vec3::r() const
{
    return e[0];
}

float Vec3::g() const
{
    return e[1];
}

float Vec3::b() const
{
    return e[2];
}

const Vec3 &Vec3::operator+() const
{
    return *this;
}

Vec3 Vec3::operator-() const
{
    return Vec3(-e[0], -e[1], -e[2]);
}

float Vec3::operator[](int i) const
{
    return e[i];
}

float &Vec3::operator[](int i)
{
    return e[i];
}

Vec3& Vec3::operator+=(const Vec3 &v)
{
    e[0] += v.e[0];
    e[1] += v.e[1];
    e[2] += v.e[2];
    return *this;
}

Vec3& Vec3::operator-=(const Vec3 &v)
{
    e[0] -= v.e[0];
    e[1] -= v.e[1];
    e[2] -= v.e[2];
    return *this;
}

Vec3& Vec3::operator*=(const Vec3 &v)
{
    e[0] *= v.e[0];
    e[1] *= v.e[1];
    e[2] *= v.e[2];
    return *this;
}

Vec3& Vec3::operator/=(const Vec3 &v)
{
    e[0] /= v.e[0];
    e[1] /= v.e[1];
    e[2] /= v.e[2];
    return *this;
}

Vec3& Vec3::operator*=(const float t)
{
    e[0] *= t;
    e[1] *= t;
    e[2] *= t;
    return *this;
}

Vec3& Vec3::operator/=(const double t)
{
    return *this *= 1/t;
}

float Vec3::length() const
{
    return sqrt(length_squared());
}

float Vec3::length_squared() const
{
    return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
}

bool Vec3::near_zero() const
{
    const auto s = 1e-8;
    return (fabs(e[0]) < s) && (fabs(e[1]) < s) && (fabs(e[2]) < s);
}

float Vec3::random_double()
{
    return rand() / (RAND_MAX + 1.0);
}

float Vec3::random_double(float min, float max)
{
    return min + (max - min) * random_double();
}

Vec3 Vec3::random()
{
    return Vec3(random_double(), random_double(), random_double());
}

Vec3 Vec3::random(float min, float max)
{
    return Vec3(random_double(min, max), random_double(min, max), random_double(min, max));
}

std::ostream &operator<<(std::ostream &out, const Vec3 &v)
{
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

std::istream &operator>>(std::istream &in, Vec3 &v)
{
    return in >> v.e[0] >> v.e[1] >> v.e[2];
}

Vec3 operator+(const Vec3 &u, const Vec3 &v)
{
    return Vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

Vec3 operator-(const Vec3 &u, const Vec3 &v)
{
    return Vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

Vec3 operator*(const Vec3 &u, const Vec3 &v)
{
    return Vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

Vec3 operator*(float t, const Vec3 &v)
{
    return Vec3(t * v.e[0], t * v.e[1], t * v.e[2]);
}

Vec3 operator*(const Vec3 &v, float t)
{
    return Vec3(t * v.e[0], t * v.e[1], t * v.e[2]);
}

Vec3 operator/(Vec3 v, float t)
{
    return (1/t) * v;
}

double dot(const Vec3 &u, const Vec3 &v)
{
    return u.e[0] * v.e[0] + u.e[1] * v.e[1] + u.e[2] * v.e[2];
}

Vec3 cross(const Vec3 &u, const Vec3 &v)
{
    return Vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
                u.e[2] * v.e[0] - u.e[0] * v.e[2],
                u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

Vec3 unit_vector(Vec3 v)
{
    return v / v.length();
}

Vec3 reflect(const Vec3 &v, const Vec3 &n)
{
    return v - 2 * dot(v, n) * n;
}

bool refract(const Vec3 &uv, const Vec3 &n, float etai_over_etat, Vec3 &refracted)
{
    Vec3 unit_vector_uv = unit_vector(uv);
    float dt = dot(unit_vector_uv, n);
    float discriminant = 1.0 - etai_over_etat * etai_over_etat * (1 - dt * dt);
    if (discriminant > 0) {
        refracted = etai_over_etat * (unit_vector_uv - n * dt) - n * sqrt(discriminant);
        return true;
    } else {
        return false;
    }
}

float schlick(float cosine, float ref_idx)
{
    float r0 = (1 - ref_idx) / (1 + ref_idx);
    r0 = r0 * r0;
    return r0 + (1 - r0) * pow((1 - cosine), 5);
}

Vec3& Vec3::normalize() {
    float len = length();
    if (len > 0) {
        e[0] /= len;
        e[1] /= len;
        e[2] /= len;
    }
    return *this;
}
