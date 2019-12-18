/*
** EPITECH PROJECT, 2019
** MUL_my_runner
** File description:
** blocs.c
*/
#include <entitybase.h>

void my_jump(entity_t *self, entity_t *target)
{
    if (target->gravity > 0.f)
        target->vel.y = -51.2f;
    else
        target->vel.y = 51.2f;
}

void my_kill(entity_t *self, entity_t *target)
{
    target->health -= 5;
}

void my_gravity_inverter(entity_t *entity, entity_t *target)
{
    target->gravity = -target->gravity;
}

void my_jump_sphere(entity_t *self, entity_t *target)
{
    if (sfKeyboard_isKeyPressed(sfKeySpace)) {
        self->health = 0;
        if (target->gravity > 0.f)
            target->vel.y = -38.4f;
        else
            target->vel.y = 38.4f;
    }
}

void my_overjump_sphere(entity_t *self, entity_t *target)
{
    if (sfKeyboard_isKeyPressed(sfKeySpace)) {
        self->health = 0;
        if (target->gravity > 0.f)
            target->vel.y = -51.2f;
        else
            target->vel.y = 51.2f;
    }
}
