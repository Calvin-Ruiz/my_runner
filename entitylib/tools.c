/*
** EPITECH PROJECT, 2019
** entitylib
** File description:
** tools.c
*/
#include <entitybase.h>

void apply_all(entitylist_t *self, void (*action)(), void *args)
{
    short i = -1;

    while (++i < self->len) {
        if (self->list[i] != NULL)
            action(self->list[i], args);
    }
}

void apply_all_custom(entitylist_t *self, void *args)
{
    short i = -1;

    while (++i < self->len) {
        if (self->list[i] != NULL)
            self->list[i]->custom(self->list[i], args);
    }
}

uint_t *get_size(uint_t width, uint_t height, uint_t nbr_rows)
{
    uint_t *size = malloc(sizeof(uint_t) * 3);

    size[0] = width;
    size[1] = height;
    size[2] = nbr_rows;
    return (size);
}

sfVector2f *get_pos(float x, float y)
{
    sfVector2f *pos = malloc(sizeof(sfVector2f) << 1);

    pos[0].x = x;
    pos[0].y = y;
    return (pos);
}

float *get_vel(float x, float y)
{
    float *vel = malloc(sizeof(float) << 1);

    vel[0] = x;
    vel[1] = y;
    return (vel);
}
