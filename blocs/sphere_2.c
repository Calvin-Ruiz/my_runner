/*
** EPITECH PROJECT, 2019
** MUL_my_runner
** File description:
** sphere_2.c
*/
#include <entitybase.h>
#include <data_storage.h>

void my_cinetic_boost_sphere(entity_t *self, entity_t *target)
{
    data_storage_t *data = get_data_storage();

    if (data->spacebar && target->size == data->entities[0]->size) {
        self->health = 0;
        target->vel.y *= 1.5f;
    }
}

void my_cinetic_inverter_sphere(entity_t *self, entity_t *target)
{
    data_storage_t *data = get_data_storage();

    if (data->spacebar && target->size == data->entities[0]->size) {
        self->health = 0;
        target->vel.y = -target->vel.y;
    }
}

void my_tp_sphere(entity_t *self, entity_t *target)
{
    data_storage_t *data = get_data_storage();

    if (data->spacebar && target->size == data->entities[0]->size) {
        self->health = 0;
        target->vel.y = -8.01f * target->gravity;
        if (target->gravity > 0) {
            target->pos.v1.y -= 320.f;
            target->pos.v2.y -= 320.f;
        } else {
            target->pos.v1.y += 320.f;
            target->pos.v2.y += 320.f;
        }
    }
}

void my_creation_sphere(entity_t *self, entity_t *target)
{
    data_storage_t *data = get_data_storage();

    if (data->spacebar && target->size == data->entities[0]->size) {
        self->health = 0;
        data->toggle = !data->toggle;
    }
}
