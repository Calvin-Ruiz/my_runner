/*
** EPITECH PROJECT, 2019
** entitylib
** File description:
** collider.c
*/
#include "include/entitybase.h"
#include "include/collider.h"

void collide_all(collider_t *data)
{
    collide_solid_static(data);
    collide_solid_dynamic(data);
    collide_fired(data);
    collide_mob(data);
}
