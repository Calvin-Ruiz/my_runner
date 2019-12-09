/*
** EPITECH PROJECT, 2019
** entitylib
** File description:
** entitylist.c
*/
#include <entity.h>

void entitylist_blits(entitylist_t *self, sfRenderWindow *window)
{
    short i = -1;

    while (++i < self->len) {
        if (self->list[i] != NULL)
            entity_blit(self->list[i], window);
    }
}

void entitylist_updates(entitylist_t *self)
{
    short i = -1;
    sfTime time = sfClock_getElapsedTime(self->clock);
    float delta_time = (time.microseconds - self->last) / 1000000.f;

    self->last = time.microseconds;
    while (++i < self->len) {
        if (self->list[i] == NULL)
            continue;
        if (self->list[i]->health <= 0) {
            free(self->list[i]);
            self->list[i] = NULL;
        } else
            self->list[i]->update(self->list[i], delta_time);
    }
}

void entitylist_append(entitylist_t *self, entity_t *entity)
{
    short i = -1;

    while (++i < self->len) {
        if (self->list[i] == NULL) {
            self->list[i] = entity;
            return;
        }
    }
    free(entity);
    write(2, "Entitylist full: cannot add entity\n", 35);
}

entitylist_t *create_entitylist(ushort_t len)
{
    entitylist_t *new = malloc(sizeof(entitylist_t));

    new->len = len;
    new->list = malloc(sizeof(void *) * len);
    short i = -1;
    while (++i < len)
        new->list[i] = NULL;
    new->last = 0;
    new->clock = sfClock_create();
    return (new);
}

void destroy_entitylist(entitylist_t *entitylist)
{
    short i = -1;

    if (entitylist == NULL)
        return;
    while (++i < entitylist->len) {
        if (entitylist->list[i] != NULL)
            free(entitylist->list[i]);
    }
    free(entitylist->list);
    sfClock_destroy(entitylist->clock);
    free(entitylist);
}
