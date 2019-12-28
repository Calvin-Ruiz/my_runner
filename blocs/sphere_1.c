/*
** EPITECH PROJECT, 2019
** MUL_my_runner
** File description:
** sphere_1.c
*/
#include <entitybase.h>
#include <data_storage.h>

void my_jump_sphere(entity_t *self, entity_t *target)
{
    data_storage_t *data = get_data_storage();

    if (data->spacebar && target->size == data->entities[0]->size) {
        self->health = 0;
        target->vel.y = -9.f * target->gravity;
    }
}

void my_overjump_sphere(entity_t *self, entity_t *target)
{
    data_storage_t *data = get_data_storage();

    if (data->spacebar && target->size == data->entities[0]->size) {
        self->health = 0;
        target->vel.y = -11.f * target->gravity;
    }
}

void my_anti_jump_sphere(entity_t *self, entity_t *target)
{
    data_storage_t *data = get_data_storage();

    if (data->spacebar && target->size == data->entities[0]->size) {
        self->health = 0;
        target->vel.y = 9.f * target->gravity;
    }
}

void my_gravity_inverter_sphere(entity_t *self, entity_t *target)
{
    data_storage_t *data = get_data_storage();

    if (data->spacebar && target->size == data->entities[0]->size) {
        self->health = 0;
        target->gravity = -target->gravity;
    }
}
