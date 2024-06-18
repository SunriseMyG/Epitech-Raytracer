/*
** EPITECH PROJECT, 2024
** B-OOP-400-NCE-4-1-raytracer-steven.deffontaine [WSL : Ubuntu]
** File description:
** Materials
*/

#include "../Ray/Ray.hpp"
#include "../../Textures/Textures.hpp"
#include "../../Textures/TexturesFromFiles.hpp"
#include "../../Object/Sphere.hpp"

#ifndef MATERIALS_HPP_
    #define MATERIALS_HPP_

    struct hit_record;

    class Materials {
        public:
            Materials() = default;
            ~Materials() = default;
            virtual bool scatter(const Ray &r_in, const hit_record &rec, Vec3 &attenuation, Ray &scattered) const = 0;
            virtual Vec3 emitted(double u, double v, const Vec3 &p) const = 0;
        protected:
        private:
    };

    class Lambertian : public Materials {
        public:
            Lambertian(const Vec3 &a) : Tex(std::make_shared<Solid_color>(albedo)) { (void)a; }
            Lambertian(std::shared_ptr<Textures> Tex) : Tex(Tex) {}
            virtual bool scatter(const Ray &r_in, const hit_record &rec, Vec3 &attenuation, Ray &scattered) const {
                (void)r_in;
                // Vec3 target = rec.p + rec.normal + Sphere::random_in_unit_sphere();

                auto scatter_direction = rec.normal + Sphere::random_in_unit_sphere();

                if (scatter_direction.near_zero())
                    scatter_direction = rec.normal;

                scattered = Ray(rec.p, scatter_direction, r_in.time());
                attenuation = Tex->Value(rec.u, rec.v, rec.p);
                return true;

                // scattered = Ray(rec.p, target - rec.p);
                // attenuation = albedo;
                // return true;
            }
            virtual Vec3 emitted(double u, double v, const Vec3 &p) const {
                (void)u;
                (void)v;
                (void)p;
                return Vec3(0, 0, 0);
            }

        protected:
        private:
            Vec3 albedo;
            std::shared_ptr<Textures> Tex;
    };

    class Metal : public Materials {
        public:
            Metal(const Vec3 &a, float f) : albedo(a) {if(f<1) fuzz=f; else fuzz=1;}
            virtual bool scatter(const Ray &r_in, const hit_record &rec, Vec3 &attenuation, Ray &scattered) const {
                Vec3 reflected = reflect(unit_vector(r_in.direction()), rec.normal);
                scattered = Ray(rec.p, reflected + fuzz * Sphere::random_in_unit_sphere());
                attenuation = albedo;
                return (dot(scattered.direction(), rec.normal) > 0);
            }
            virtual Vec3 emitted(double u, double v, const Vec3 &p) const {
                (void)u;
                (void)v;
                (void)p;
                return Vec3(0, 0, 0);
            }

        protected:
        private:
            Vec3 albedo;
            int fuzz;
    };

    class Dielectric : public Materials {
        public:
            Dielectric(float ri) : refect_index(ri) {};
            virtual bool scatter(const Ray& r_in, const hit_record& rec, Vec3& attenuation, Ray& scattered) const  {
                Vec3 outward_normal;
                Vec3 reflected = reflect(r_in.direction(), rec.normal);
                float ni_over_nt;
                attenuation = Vec3(1.0, 1.0, 1.0);
                Vec3 refracted;
                float reflect_prob;
                float cosine;
                if (dot(r_in.direction(), rec.normal) > 0) {
                    outward_normal = -rec.normal;
                    ni_over_nt = refect_index;
                    // cosine = ref_idx * dot(r_in.direction(), rec.normal) / r_in.direction().length();
                    cosine = dot(r_in.direction(), rec.normal) / r_in.direction().length();
                    cosine = sqrt(1 - refect_index * refect_index * (1 - cosine * cosine));
                }
                else {
                    outward_normal = rec.normal;
                    ni_over_nt = 1.0 / refect_index;
                    cosine = -dot(r_in.direction(), rec.normal) / r_in.direction().length();
                }
                if (refract(r_in.direction(), outward_normal, ni_over_nt, refracted))
                    reflect_prob = schlick(cosine, refect_index);
                else
                    reflect_prob = 1.0;
                if (drand48() < reflect_prob)
                    scattered = Ray(rec.p, reflected);
                else
                    scattered = Ray(rec.p, refracted);
                return true;
            }
            virtual Vec3 emitted(double u, double v, const Vec3 &p) const {
                (void)u;
                (void)v;
                (void)p;
                return Vec3(0, 0, 0);
            }

        protected:
        private:
            float refect_index;
    };

    class Diffuse_Light : public Materials {
        public:
            Diffuse_Light(std::shared_ptr<Textures> tex) : emit(tex) {}
            Diffuse_Light(const Vec3 &c) : emit(std::make_shared<Solid_color>(c)) {}

            virtual bool scatter(const Ray &r_in, const hit_record &rec, Vec3 &attenuation, Ray &scattered) const {
                (void)r_in;
                (void)rec;
                (void)attenuation;
                (void)scattered;
                return false;
            }

            virtual Vec3 emitted(double u, double v, const Vec3 &p) const override {
                return emit->Value(u, v, p);
            }

        private:
            std::shared_ptr<Textures> emit;
    };


#endif /* !MATERIALS_HPP_ */
