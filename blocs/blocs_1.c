/*
** EPITECH PROJECT, 2019
** MUL_my_runner
** File description:
** blocs_1.c
*/
#include <entitybase.h>
#include <data_storage.h>

void my_jump(entity_t *self, entity_t *target)
{
    target->vel.y = -11.01f * target->gravity;
}

void my_kill(entity_t *self, entity_t *target)
{
    target->health -= 24;
}

void my_gravity_inverter(entity_t *entity, entity_t *target)
{
    target->gravity = -target->gravity;
}

void my_ice(entity_t *self, entity_t *target)
{
    target->vel.y -= 0.01f;
}

void my_stick(entity_t *self, entity_t *target)
{
    if (!get_data_storage()->spacebar)
        target->vel.y -= target->gravity * 1.01f;
}
