/*
** EPITECH PROJECT, 2019
** entitylib
** File description:
** hollow.c
*/
#include <entity.h>

entity_t *create_hollow(sfTexture *t, uint_t *size, float fdelay,
    void (*custom)(entity_t *self, entity_t *target))
{
    entity_t *new = malloc(sizeof(entity_t));

    if (new == NULL || t == NULL || size == NULL)
        return (NULL);
    new->sprite = malloc(sizeof(void *) * size[2] * 4);
    if (new->sprite == NULL)
        return (NULL);
    create_sprite(new->sprite, t, size);
    new->size = size;
    new->health = 16;
    new->frame_delay = fdelay * 1000000;
    new->update = no_update;
    new->custom = custom;
    new->custom_x = custom;
    new->custom_y = custom;
    new->gravity = 4.f;
    return (new);
}
