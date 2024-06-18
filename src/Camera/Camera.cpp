/*
** EPITECH PROJECT, 2024
** B-OOP-400-NCE-4-1-raytracer-steven.deffontaine [WSL : Ubuntu]
** File description:
** Camera
*/

#include "Camera.hpp"

Camera::Camera(Parsing &parsing)
{
    _position = Vec3(parsing.getCamera().position.x, parsing.getCamera().position.y, parsing.getCamera().position.z);
    _rotation = Vec3(parsing.getCamera().rotation.x, parsing.getCamera().rotation.y, parsing.getCamera().rotation.z);
    _fov = parsing.getCamera().fov;
    _dof = parsing.getCamera().dof;
    _aperture = 0.1;

    float ratio = float(parsing.getCamera().resolution.width) / float(parsing.getCamera().resolution.height);
    Vec3 lookfrom = _position;
    Vec3 lookat = Vec3(0,0, -1);
    Vec3 vup = Vec3(0,1,0);
    float focus_dist = (lookfrom - lookat).length();

    CameraCalcul(lookfrom, lookat, vup, _fov, ratio, _aperture, focus_dist);
}

void Camera::CameraCalcul(Vec3 lookfrom, Vec3 lookat, Vec3 vup, float fov, float aspect , float aperture, float focus_dist)
{
    _lens_radius = aperture / 2;
    float theta = fov * M_PI / 180;
    float half_height = tan(theta/2);
    float half_width = aspect * half_height;
    _origin = lookfrom;
    _w = unit_vector(lookfrom - lookat);
    _u = unit_vector(cross(vup, _w));
    _v = cross(_w, _u);
    _lower_left_corner = _origin - half_width * focus_dist * _u + half_height * focus_dist * _v - focus_dist * _w;
    _horizontal = 2*half_width * _u * focus_dist;
    _vertical = -2*half_height* _v *focus_dist;
}

Vec3 Camera::randomInUnitDisk()
{
    Vec3 p;
    do {
        p = 2.0 * Vec3(drand48(), drand48(), 0) - Vec3(1,1,0);
    } while (dot(p,p) >= 1.0);
    return p;
}

Ray Camera::getRay(float s, float t)
{
    Vec3 rd = _lens_radius * randomInUnitDisk();
    Vec3 offset = _u * rd.x() + _v * rd.y();
    return Ray(_origin + offset, _lower_left_corner + s * _horizontal + t * _vertical - _origin - offset);
}
