/*
** EPITECH PROJECT, 2019
** MUL_my_runner
** File description:
** portals_1.c
*/
#include <entitybase.h>
#include <data_storage.h>

void my_normal_gravity_portal(entity_t *self, entity_t *target)
{
    data_storage_t *data = get_data_storage();

    if (target->size == data->entities[0]->size) {
        self->health = 0;
        target->gravity = 4.f;
    }
}

void my_gravity_inverter_portal(entity_t *self, entity_t *target)
{
    data_storage_t *data = get_data_storage();

    if (target->size == data->entities[0]->size) {
        self->health = 0;
        target->gravity = -target->gravity;
    }
}

void my_switch_gravity_portal(entity_t *self, entity_t *target)
{
    data_storage_t *data = get_data_storage();

    if (target->size == data->entities[0]->size) {
        self->health = 0;
        if (data->toggle && target->gravity < 0.f)
            target->gravity = -target->gravity;
        else if (!data->toggle && target->gravity > 0.f)
            target->gravity = -target->gravity;
    }
}

void my_cinetic_boost_portal(entity_t *self, entity_t *target)
{
    data_storage_t *data = get_data_storage();

    if (target->size == data->entities[0]->size) {
        self->health = 0;
        target->vel.y *= 1.5f;
    }
}

void my_cinetic_inverter_portal(entity_t *self, entity_t *target)
{
    data_storage_t *data = get_data_storage();

    if (target->size == data->entities[0]->size) {
        self->health = 0;
        target->vel.y = -target->vel.y;
    }
}
