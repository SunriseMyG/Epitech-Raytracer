/*
** EPITECH PROJECT, 2024
** B-OOP-400-NCE-4-1-raytracer-steven.deffontaine [WSL : Ubuntu]
** File description:
** Textures
*/

#include "./../UtilsObject/Vec3/Vec3.hpp"
#include "./TexturesFromFiles.hpp"
#include "./Interval.hpp"
#include <memory>

#ifndef TEXTURES_HPP_
    #define TEXTURES_HPP_

    class Textures {
        public:
            Textures() = default;
            ~Textures() = default;

            virtual Vec3 Value(float u, float v, const Vec3 &p) const = 0;

        protected:
        private:
    };

    class Solid_color : public Textures {
        public:
            Solid_color(const Vec3 &albedo) : _albedo(albedo) {}
            Solid_color(double red, double green, double blue) : Solid_color(Vec3(red, green, blue)) {}
            Vec3 Value(float u, float v, const Vec3 &p) const override {
                (void)u;
                (void)v;
                (void)p;
                return _albedo; 
            }
        protected:
            Vec3 _albedo;
        private:
    };

    class Checker_texture : public Textures {
        public:
            Checker_texture(double scale, std::shared_ptr<Textures> even, std::shared_ptr<Textures> odd)
            : inv_scale(1.0 / scale), even(even), odd(odd) {}
            Checker_texture(double scale, const Vec3 &c1, const Vec3 &c2)
            : inv_scale(1.0 / scale), even(std::make_shared<Solid_color>(c1)), odd(std::make_shared<Solid_color>(c2)) {}
            Vec3 Value(float u, float v, const Vec3 &p) const override;
        protected:
        private:
            double inv_scale;
            std::shared_ptr<Textures> even;
            std::shared_ptr<Textures> odd;
    };


    class Image_texture : public Textures {
        public:
            Image_texture(const char *filename) : _image(filename) {};
            Vec3 Value(float u, float v, const Vec3 &p) const override;
        protected:
        private:
            TexturesFromFiles _image;
    };

#endif /* !TEXTURES_HPP_ */
