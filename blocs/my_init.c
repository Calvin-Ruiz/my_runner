/*
** EPITECH PROJECT, 2019
** MUL_my_runner
** File description:
** my_init.c
*/
#include "include/my_init.h"
#include <data_storage.h>

static void my_init_defaults(int i, int j, data_storage_t *datas)
{
    entity_t *my_unknown = create_surface(datas->textures[3],
        get_size(64, 64, 1), 0.12f, no_custom);

    datas->entities[i++] = create_fired(datas->textures[j],
        get_size(24, 8, 1), 2.f, 1);
    datas->entities[i] = create_fired(datas->textures[2],
        get_size(1, 64 * 64, 1), 2.f, 1073741824);
    datas->entities[i++]->custom = my_barrier;
    datas->nb_entity = i + 1;
    while (i < 64)
        datas->entities[i++] = my_unknown;
}

static void my_init_entity_bases_4(int i, int j, data_storage_t *datas)
{
    datas->entities[i++] = create_hollow(datas->textures[j++],
        get_size(64, 192, 1), 0.12f, my_gravity_inverter_portal);
    datas->entities[i++] = create_hollow(datas->textures[j++],
        get_size(64, 192, 1), 0.12f, my_switch_gravity_portal);
    datas->entities[i++] = create_hollow(datas->textures[j++],
        get_size(64, 192, 1), 0.12f, my_cinetic_boost_portal);
    datas->entities[i++] = create_hollow(datas->textures[j++],
        get_size(64, 192, 1), 0.12f, my_cinetic_inverter_portal);
    datas->entities[i++] = create_hollow(datas->textures[j++],
        get_size(64, 192, 1), 0.12f, no_custom);
    datas->entities[i++] = create_hollow(datas->textures[j++],
        get_size(64, 192, 1), 0.12f, no_custom);
    datas->entities[i++] = create_hollow(datas->textures[j++],
        get_size(64, 192, 1), 0.12f, no_custom);
    datas->entities[i++] = create_hollow(datas->textures[j++],
        get_size(64, 192, 1), 0.12f, no_custom);
    datas->entities[i++] = create_g_entity(datas->textures[j++],
        get_size(64, 64, 1), 0.12f, 2);
    my_init_defaults(i, j, datas);
}

static void my_init_entity_bases_3(int i, int j, data_storage_t *datas)
{
    datas->entities[i++] = create_hollow(datas->textures[j++],
        get_size(64, 64, 1), 0.12f, my_gravity_inverter_sphere);
    datas->entities[i++] = create_hollow(datas->textures[j++],
        get_size(64, 64, 1), 0.12f, my_cinetic_inverter_sphere);
    datas->entities[i++] = create_hollow(datas->textures[j++],
        get_size(64, 64, 1), 0.12f, my_cinetic_boost_sphere);
    datas->entities[i++] = create_hollow(datas->textures[j++],
        get_size(64, 64, 1), 0.12f, my_tp_sphere);
    datas->entities[i++] = create_hollow(datas->textures[j++],
        get_size(64, 64, 1), 0.12f, my_creation_sphere);
    datas->entities[i++] = create_hollow(datas->textures[j++],
        get_size(64, 192, 1), 0.12f, no_custom);
    datas->entities[i++] = create_hollow(datas->textures[j++],
        get_size(64, 192, 1), 0.12f, no_custom);
    datas->entities[i++] = create_hollow(datas->textures[j++],
        get_size(64, 192, 1), 0.12f, no_custom);
    datas->entities[i++] = create_hollow(datas->textures[j++],
        get_size(64, 192, 1), 0.12f, my_normal_gravity_portal);
    my_init_entity_bases_4(i, j, datas);
}

static void my_init_entity_bases_2(int i, int j, data_storage_t *datas)
{
    datas->entities[i++] = create_hollow(datas->textures[j++],
        get_size(64, 64, 1), 0.12f, my_cinetic_inverter);
    datas->entities[i++] = create_hollow(datas->textures[j++],
        get_size(64, 64, 1), 0.12f, my_water);
    datas->entities[i++] = create_hollow(datas->textures[j++],
        get_size(64, 64, 1), 0.12f, my_bubble);
    datas->entities[i] = create_surface(datas->textures[j++],
        get_size(64, 64, 1), 0.12f, no_custom);
    datas->entities[i++]->update = my_switch;
    datas->entities[i] = create_surface(datas->textures[j++],
        get_size(64, 64, 1), 0.12f, no_custom);
    datas->entities[i++]->update = my_switch;
    datas->entities[i++] = create_hollow(datas->textures[j++],
        get_size(64, 64, 1), 0.12f, my_jump_sphere);
    datas->entities[i++] = create_hollow(datas->textures[j++],
        get_size(64, 64, 1), 0.12f, my_overjump_sphere);
    datas->entities[i++] = create_hollow(datas->textures[j++],
        get_size(64, 64, 1), 0.12f, my_anti_jump_sphere);
    my_init_entity_bases_3(i, j, datas);
}

void my_init_entity_bases(data_storage_t *datas)
{
    int i = 0;
    int j = 4;

    datas->entities[i++] = create_player_entity(datas->textures[j++],
        get_size(64, 64, 3), 0.12f, 3);
    datas->entities[i++] = create_surface(datas->textures[j++],
        get_size(64, 64, 1), 0.12f, no_custom);
    datas->entities[i++] = create_hollow(datas->textures[j++],
        get_size(64, 64, 1), 0.12f, my_kill);
    datas->entities[i++] = create_surface(datas->textures[j++],
        get_size(64, 64, 1), 0.12f, my_jump);
    datas->entities[i++] = create_surface(datas->textures[j++],
        get_size(64, 64, 1), 0.12f, my_gravity_inverter);
    datas->entities[i++] = create_surface(datas->textures[j++],
        get_size(64, 64, 1), 0.12f, my_ice);
    datas->entities[i++] = create_surface(datas->textures[j++],
        get_size(64, 64, 1), 0.12f, no_custom);
    datas->entities[i++] = create_surface(datas->textures[j++],
        get_size(64, 64, 1), 0.12f, my_stick);
    my_init_entity_bases_2(i, j, datas);
}
