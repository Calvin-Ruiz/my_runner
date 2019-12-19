/*
** EPITECH PROJECT, 2019
** MUL_my_runner
** File description:
** my_init.c
*/
#include "include/main.h"

static void my_init_defaults(int i, data_storage_t *datas)
{
    entity_t *my_unknown = create_surface(datas->textures[3],
        get_size(64, 64, 1), 0.12f, no_custom);

    datas->nb_entity = i + 1;
    while (i < 64)
        datas->entities[i++] = my_unknown;
}

static void my_init_entity_bases_2(int i, int j, data_storage_t *datas)
{
    my_init_defaults(i, datas);
}

void my_init_entity_bases(data_storage_t *datas)
{
    int i = 0;
    int j = 4;
    datas->entities[i++] = create_player_entity(datas->textures[j++],
        get_size(64, 64, 3), 0.12f, 3);
    datas->entities[i++] = create_surface(datas->textures[j++],
        get_size(64, 64, 1), 0.12f, no_custom);
    datas->entities[i++] = create_surface(datas->textures[j++],
        get_size(64, 64, 1), 0.12f, my_jump);
    datas->entities[i++] = create_hollow(datas->textures[j++],
        get_size(64, 64, 1), 0.12f, my_kill);
    datas->entities[i++] = create_surface(datas->textures[j++],
        get_size(64, 64, 1), 0.12f, my_gravity_inverter);
    datas->entities[i++] = create_hollow(datas->textures[j++],
        get_size(64, 64, 1), 0.12f, my_jump_sphere);
    datas->entities[i++] = create_hollow(datas->textures[j++],
        get_size(64, 64, 1), 0.12f, my_overjump_sphere);
    datas->entities[i] = create_fired(datas->textures[2],
        get_size(1, 64 * 32, 1), 2.f, 1073741824);
    datas->entities[i++]->custom = my_barrier;
    my_init_entity_bases_2(i, j, datas);
}
