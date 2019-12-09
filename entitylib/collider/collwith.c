/*
** EPITECH PROJECT, 2019
** entitylib
** File description:
** collwith.c
*/
#include <internal_collider.h>

void collwith_solid_static(entity_t *entity, collider_t *data)
{
    if (entity == NULL)
        return;
    int i = -1;
    int j = -1;

    while (++i < data->nb_solid_static) {
        j = -1;
        while (++j < data->solid_static[i]->len)
            fast_collide(entity, data->solid_static[i]->list[j]);
    }
}

void collwith_solid_dynamic(entity_t *entity, collider_t *data)
{
    if (entity == NULL)
        return;
    int i = -1;
    int j = -1;

    while (++i < data->nb_solid_dynamic) {
        j = -1;
        while (++j < data->solid_dynamic[i]->len)
            collide(entity, data->solid_dynamic[i]->list[j]);
    }
}

void collwith_hollow_static(entity_t *entity, collider_t *data)
{
    if (entity == NULL)
        return;
    int i = -1;
    int j = -1;

    while (++i < data->nb_hollow_static) {
        j = -1;
        while (++j < data->hollow_static[i]->len)
            collide_custom_only(entity, data->hollow_static[i]->list[j]);
    }
}

void collwith_hollow_dynamic(entity_t *entity, collider_t *data)
{
    if (entity == NULL)
        return;
    int i = -1;
    int j = -1;

    while (++i < data->nb_hollow_dynamic) {
        j = -1;
        while (++j < data->hollow_dynamic[i]->len)
            collide_custom_only(entity, data->hollow_dynamic[i]->list[j]);
    }
}

void collwith_fired(entity_t *entity, collider_t *data)
{
    if (entity == NULL)
        return;
    int i = -1;
    int j = -1;

    while (++i < data->nb_fired) {
        j = -1;
        while (++j < data->fired[i]->len)
            collide_custom_only(entity, data->fired[i]->list[j]);
    }
}
