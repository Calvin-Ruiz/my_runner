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
        target->vel.y -= 51.2f;
    else
        target->vel.y += 51.2f;
}
