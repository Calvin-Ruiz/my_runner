/*
** EPITECH PROJECT, 2019
** MUL_my_runner
** File description:
** blocs.c
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

void my_jump_sphere(entity_t *self, entity_t *target)
{
    if (sfKeyboard_isKeyPressed(sfKeySpace)) {
        self->health = 0;
        target->vel.y = -9.f * target->gravity;
    }
}

void my_overjump_sphere(entity_t *self, entity_t *target)
{
    if (sfKeyboard_isKeyPressed(sfKeySpace)) {
        self->health = 0;
        target->vel.y = -11.f * target->gravity;
    }
}
