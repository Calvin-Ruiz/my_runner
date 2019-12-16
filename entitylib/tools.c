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

void no_update(void *ptr)
{
    ptr = ptr;
}
