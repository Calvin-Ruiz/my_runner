/*
** EPITECH PROJECT, 2019
** entitylib
** File description:
** bonus.c
*/
#include <entity.h>
#include <data_storage.h>

void bonus_entity_update(entity_t *self)
{
    self->pos.v1.x += self->vel.x;
    self->pos.v1.y += self->vel.y;
    self->vel.y += self->gravity;
    self->health--;
}

entity_t *create_bonus_entity(sfTexture *t, uint_t *size, float fdelay, int hp)
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
    new->frame = 0;
    new->frame_delay = fdelay * 1000000;
    new->update = bonus_entity_update;
    new->custom = no_custom;
    return (new);
}
