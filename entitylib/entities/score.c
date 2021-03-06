/*
** EPITECH PROJECT, 2019
** entitylib
** File description:
** score.c
*/
#include <entity.h>
#include <data_storage.h>

void score_entity_update(entity_t *self)
{
    self->pos.v1.y += self->vel.y;
    self->health--;
}

entity_t *create_score_entity(sfTexture *t, uint_t *size, float fdelay, int hp)
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
    new->update = score_entity_update;
    new->custom = no_custom;
    new->custom_x = no_custom;
    new->custom_y = no_custom;
    return (new);
}
