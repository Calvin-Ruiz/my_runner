/*
** EPITECH PROJECT, 2019
** entitylib
** File description:
** entity.c
*/
#include "include/entitybase.h"

void no_custom(entity_t *self, void *args)
{
    if (self != args)
        return;
}

entity_t *new_instance(entity_t *self, pos_t pos, sfVector2f vel, uchar_t row)
{
    entity_t *new = malloc(sizeof(entity_t));

    new->pos = pos;
    new->vel = vel;
    new->frame_dec = row;
    new->sprite = self->sprite + row;
    new->size = self->size;
    new->update = self->update;
    new->custom = self->custom;
    new->frame_delay = self->frame_delay;
    new->health = self->health;
    new->frame = 0;
    new->timer = 0;
    return (new);
}

void entity_blit(entity_t *self, sfRenderWindow *window)
{
    sfSprite_setPosition(self->sprite[self->frame], self->pos.v1);
    sfRenderWindow_drawSprite(window, self->sprite[self->frame], NULL);
}

void create_sprite(sfSprite **sprite, sfTexture *texture, uint_t *size)
{
    unsigned int i = -1;
    int j;
    uint_t x;
    uint_t y = 0;
    sfIntRect rect;
    rect.width = size[0];
    rect.height = size[1];
    while (++i < size[2]) {
        j = -1;
        x = 0;
        while (++j < 4) {
            *sprite = sfSprite_create();
            sfSprite_setTexture(*sprite, texture, sfFalse);
            rect.left = x;
            rect.top = y;
            sfSprite_setTextureRect(*(sprite++), rect);
            x += size[0];
        }
        y += size[1];
    }
}

void free_entity(entity_t *entity)
{
    if (entity == NULL)
        return;
    int i = -1;
    const int end = entity->size[2] * 4;

    while (++i < end)
        sfSprite_destroy(entity->sprite[i]);
    free(entity->sprite);
    free(entity->size);
    free(entity);
}
