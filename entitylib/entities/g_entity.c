/*
** EPITECH PROJECT, 2019
** entitylib
** File description:
** g_entity.c
*/
#include <entity.h>
#include <entitylist.h>
#include <data_storage.h>

void update_g_entity(entity_t *self)
{
    self->vel.y += self->gravity;
    self->pos.v1.x += self->vel.x;
    self->pos.v1.y += self->vel.y;
    self->pos.v2.x = self->pos.v1.x + self->size[0];
    self->pos.v2.y = self->pos.v1.y + self->size[1];
}

entity_t *create_g_entity(sfTexture *t, uint_t *size, float fdelay, int hp)
{
    entity_t *new = malloc(sizeof(entity_t));

    if (new == NULL || t == NULL || size == NULL)
        return (NULL);
    new->sprite = malloc(sizeof(void *) * size[2] * 4);
    if (new->sprite == NULL)
        return (NULL);
    create_sprite(new->sprite, t, size);
    new->size = size;
    new->health = hp;
    new->frame_delay = fdelay * 1000000;
    new->update = update_g_entity;
    new->custom = no_custom;
    new->custom_x = no_custom;
    new->custom_y = no_custom;
    new->gravity = 4.f;
    return (new);
}
