/*
** EPITECH PROJECT, 2019
** entitylib
** File description:
** fired.c
*/
#include <entity.h>

void my_dmg(entity_t *self, entity_t *target)
{
    int tmp = target->health;
    target->health -= self->health;
    self->health = (self->health > tmp) ? self->health - tmp : 0;
}

void my_barrier(entity_t *self, entity_t *target)
{
    target->health -= self->health;
}

void update_fired(entity_t *self)
{
    self->pos.v1.x += self->vel.x;
    self->pos.v1.y += self->vel.y;
    self->pos.v2.x = self->pos.v1.x + *(self->size);
    self->pos.v2.y = self->pos.v1.y + self->size[1];
}

entity_t *create_fired(sfTexture *t, uint_t *size, float fdelay, int hp)
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
    new->update = update_fired;
    new->custom = my_dmg;
    new->custom_x = no_custom;
    new->custom_y = no_custom;
    new->gravity = 4.f;
    return (new);
}
