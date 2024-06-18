/*
** EPITECH PROJECT, 2024
** B-OOP-400-NCE-4-1-raytracer-steven.deffontaine [WSL : Ubuntu]
** File description:
** Camera
*/

#include "../UtilsObject/Ray/Ray.hpp"
#include "../Parsing/Parsing.hpp"


#ifndef CAMERA_HPP_
    #define CAMERA_HPP_

    class Camera {
        public:
            Camera(Parsing &parsing);
            void CameraCalcul(Vec3 lookfrom, Vec3 lookat, Vec3 vup, float fov, float aspect , float aperture, float focus_dist);
            ~Camera() = default;

            Vec3 randomInUnitDisk();

            //getters
            Ray getRay(float u, float v);

        protected:
            Vec3 _lower_left_corner;
            Vec3 _horizontal;
            Vec3 _vertical;
            Vec3 _origin;
            float _lens_radius;
            Vec3 _w;
            Vec3 _u;
            Vec3 _v;

            Vec3 _position;
            Vec3 _rotation;
            float _fov;
            float _dof;
            float _aperture;
        private:
    };

#endif /* !CAMERA_HPP_ */
