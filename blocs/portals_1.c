/*
** EPITECH PROJECT, 2019
** MUL_my_runner
** File description:
** portals_1.c
*/
#include <entitybase.h>

void my_normal_gravity_portal(entity_t *self, entity_t *target)
{
    data_storage_t *data = get_data_storage();

    if (target->size == data->entities[0]->size) {
        self->health = 0;
        self->gravity = 4.f;
    }
}

void my_gravity_inverter_portal(entity_t *self, entity_t *target)
{
    data_storage_t *data = get_data_storage();

    if (target->size == data->entities[0]->size) {
        self->health = 0;
        self->gravity = -self->gravity;
    }
}
