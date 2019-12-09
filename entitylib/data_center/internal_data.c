/*
** EPITECH PROJECT, 2019
** entitylib
** File description:
** internal_data.c
*/
#include <entitybase.h>
#include <internal_data.h>

internal_data_t *get_internal_data(void)
{
    static internal_data_t data;
    return (&data);
}
