/*
** EPITECH PROJECT, 2024
** B-OOP-400-NCE-4-1-raytracer-steven.deffontaine [WSL : Ubuntu]
** File description:
** Hitable_list
*/

#include "Hitable_list.hpp"

Hitable_list::Hitable_list(Hitable **l, int n)
{
    printf("Hitable_list List:\n");
    for (int i = 0; i < n; i++) {
        printf("\tHitable_list[%d]: %p\n", i, l[i]);
    }
    _list = l;
    _list_size = n;
}

bool Hitable_list::hit(const Ray &r, float t_min, float t_max, hit_record &rec) const
{
    hit_record temp_rec;
    bool hit_anything = false;
    double closest_so_far = t_max;

    for (int i = 0; i < _list_size; i++) {
        if (_list[i]->hit(r, t_min, closest_so_far, temp_rec)) {
            hit_anything = true;
            closest_so_far = temp_rec.t;
            rec = temp_rec;
        }
    }
    return hit_anything;
}

void Hitable_list::dumpData() const
{
    printf("Hitable_list List:\n");
    for (int i = 0; i < _list_size; i++) {
        printf("\tHitable_list[%d]: %p\n", i, _list[i]);
    }
}