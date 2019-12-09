/*
** EPITECH PROJECT, 2019
** entitylib
** File description:
** player.c
*/
#include <entity.h>
#include <player.h>

void update_player(entity_t *self)
{
    if (++(self->timer) > self->frame_delay) {
        self->timer = 0;
        self->frame = (self->frame + 1) & 3;
    }
}

player_t *create_player(sfTexture *t, uint_t *size, float fdelay, int hp)
{
    player_t *player = malloc(sizeof(player_t));
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
    new->update = update_player;
    new->custom = no_custom;
    player->entity = new;
    return (player);
}
