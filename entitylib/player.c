/*
** EPITECH PROJECT, 2019
** entitylib
** File description:
** player.c
*/
#include <entity.h>
#include <player.h>
#include <data_storage.h>

void update_player(entity_t *self)
{
    self->vel.y += self->gravity;
    self->pos.v1.x += self->vel.x;
    self->pos.v1.y += self->vel.y;
    self->pos.v2.x = self->pos.v1.x + self->size[0];
    self->pos.v2.y = self->pos.v1.y + self->size[1];
}

entity_t *create_player_entity(sfTexture *t, uint_t *size, float fdelay, int hp)
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
    new->update = update_player;
    new->custom = no_custom;
    new->gravity = 4.f;
    return (new);
}

player_t *create_player(int nb_cols)
{
    data_storage_t *datas = get_data_storage();
    player_t *player = malloc(sizeof(player_t));

    if (player == NULL)
        return (NULL);
    player->entity = new_instance(datas->entities[0],
        (pos_t) {(sfVector2f) {256, 64 * (nb_cols - 2)},
        (sfVector2f) {320, 64 * (nb_cols - 1)}}, (sfVector2f) {0, 0}, 0);
    if (player->entity == NULL)
        return (NULL);
    return (player);
}
