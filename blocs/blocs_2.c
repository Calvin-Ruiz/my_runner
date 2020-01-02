/*
** EPITECH PROJECT, 2019
** MUL_my_runner
** File description:
** blocs_2.c
*/
#include <entitybase.h>

void my_water(entity_t *self, entity_t *target)
{
    target->vel.y *= 0.9f;
    return;
}

void my_bubble(entity_t *self, entity_t *target)
{
    target->vel.y = -2.5f * target->gravity;
}

void my_cinetic_inverter(entity_t *self, entity_t *target)
{
    if (target->gravity < 0 && target->vel.y > 0)
        target->vel.y = -target->vel.y;
    else if (target->gravity > 0 && target->vel.y < 0)
        target->vel.y = -target->vel.y;
}

void my_switch(entity_t *self)
{
    self = self;
}
