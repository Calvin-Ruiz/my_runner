/*
** EPITECH PROJECT, 2019
** entitylib
** File description:
** g_entity.c
*/
#include <entity.h>
#include <entitylist.h>
#include <data_storage.h>

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
    new->update = no_update;
    new->custom = no_custom;
    return (new);
}
