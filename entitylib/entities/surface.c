/*
** EPITECH PROJECT, 2019
** entitylib
** File description:
** surface.c
*/
#include <entity.h>

void surface_update(entity_t *self)
{
}

entity_t *create_surface(sfTexture *t, uint_t *size, float fdelay,
    void (*custom)(entity_t *self, void *args))
{
    entity_t *new = malloc(sizeof(entity_t));

    if (new == NULL || t == NULL || size == NULL)
        return (NULL);
    new->sprite = malloc(sizeof(void *) * size[2] * 4);
    if (new->sprite == NULL)
        return (NULL);
    create_sprite(new->sprite, t, size);
    new->size = size;
    new->health = 2147483647;
    new->frame_delay = fdelay * 1000000;
    new->update = surface_update;
    new->custom = custom;
    return (new);
}
