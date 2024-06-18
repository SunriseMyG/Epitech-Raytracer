/*
** EPITECH PROJECT, 2024
** B-OOP-400-NCE-4-1-raytracer-steven.deffontaine [WSL : Ubuntu]
** File description:
** Hitable_list
*/

#include "Hitable.hpp"

#ifndef HITABLE_LIST_HPP_
    #define HITABLE_LIST_HPP_

    class Hitable_list : public Hitable {
        public:
            Hitable_list() {};
            ~Hitable_list() = default;

            Hitable_list(Hitable **l, int n);
            virtual bool hit(const Ray &r, float t_min, float t_max, hit_record &rec) const;
            void dumpData() const;
            protected:
                Hitable **_list;
                int _list_size;
            private:
    };

#endif /* !HITABLE_LIST_HPP_ */
