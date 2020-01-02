/*
** EPITECH PROJECT, 2019
** entitylib
** File description:
** hollow.c
*/
#include <entity.h>

void hollow_damagement(entity_t *self)
{
    self->health--;
}

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
    new->health = 60;
    new->frame_delay = fdelay * 1000000;
    new->update = hollow_damagement;
    new->custom = custom;
    new->custom_x = custom;
    new->custom_y = custom;
    new->gravity = 4.f;
    return (new);
}
