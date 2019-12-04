/*
** EPITECH PROJECT, 2019
** entitylib
** File description:
** basic_entity.c
*/
#include "include/entity.h"
#include "include/entitylist.h"
#include "include/data_storage.h"

void basic_entity_update(entity_t *self, float delta_time)
{
    self->timer += delta_time;
    if (self->timer > self->frame_delay) {
        self->timer -= self->frame_delay;
        self->frame = (self->frame + 1) & 3;
    }
    self->pos.v1.x += self->vel.x * delta_time;
    self->pos.v1.y += self->vel.y * delta_time;
    self->pos.v2.x = self->pos.v1.x + self->size[0];
    self->pos.v2.y = self->pos.v1.y + self->size[1];
    if (self->pos.v1.x > 1600 || self->pos.v2.x < 0) {
        data_storage_t *datas = get_data_storage();
        datas->health -= self->health & 1;
        self->health = 0;
    }
}

entity_t *create_base_entity(sfTexture *t, uint_t *size, float fdelay, int hp)
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
    new->frame_delay = fdelay;
    new->update = basic_entity_update;
    new->custom = no_custom;
    return (new);
}

void killed_basic_entity_update(entity_t *self, float delta_time)
{
    self->timer += delta_time;
    self->pos.v1.x += self->vel.x * delta_time;
    self->pos.v1.y = self->pos.v2.y + self->timer * (self->vel.y +
        400.f * self->timer);
    if (self->pos.v1.y > 800.f)
        self->health = 0;
}

void kill_base_entity(entity_t *self, float vel_y)
{
    self->timer = 0;
    self->pos.v2.y = self->pos.v1.y;
    self->vel.y = vel_y;
    self->sprite += ((self->size[2] - 1) << 2) - self->frame_dec;
    self->frame = self->frame_dec >> 2;
    self->frame_dec = (self->size[2] - 1) << 2;
    self->frame_delay = 0;
    self->update = killed_basic_entity_update;
}
