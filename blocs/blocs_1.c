/*
** EPITECH PROJECT, 2019
** MUL_my_runner
** File description:
** blocs_1.c
*/
#include <entitybase.h>

void my_jump(entity_t *self, entity_t *target)
{
    target->vel.y = -11.f * target->gravity;
}

void my_kill(entity_t *self, entity_t *target)
{
    target->health -= 3;
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
    if (!sfKeyboard_isKeyPressed(sfKeySpace))
        target->vel.y -= target->gravity * 1.01f;
}
