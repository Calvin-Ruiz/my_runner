/*
** EPITECH PROJECT, 2019
** entitylib
** File description:
** data_storage.c
*/
#include <entitylib.h>
#include <converters.h>

data_storage_t *get_data_storage(void)
{
    static data_storage_t storage;
    return (&storage);
}

static void init_data_storage_2(data_storage_t *datas)
{
    int_to_raw_t conv;
    float_to_raw_t conv2;
    int fd = open("saves/scoreboard.dat", O_RDONLY);

    datas->higher_score = 0;
    datas->volume = 100.f;
    if (fd != -1) {
        if (read(fd, conv.raw, 4) == 4)
            datas->higher_score = conv.value;
        if (read(fd, conv2.raw, sizeof(conv2.value)) == sizeof(conv2.value))
            datas->volume = conv2.value;
        close(fd);
    }
}

data_storage_t *init_data_storage(int nb_sounds, int nb_textures,
    int nb_entity, int nb_entitylist)
{
    data_storage_t *datas = get_data_storage();

    datas->sound_buffs = malloc(sizeof(*(datas->sound_buffs)) * nb_sounds);
    datas->sounds = malloc(sizeof(*(datas->sounds)) * nb_sounds);
    datas->nb_sounds = nb_sounds;
    datas->textures = malloc(sizeof(*(datas->textures)) * nb_textures);
    datas->nb_textures = nb_textures;
    datas->entities = malloc(sizeof(*(datas->entities)) * nb_entity);
    datas->nb_entity = nb_entity;
    datas->entitylists = malloc(sizeof(*(datas->entitylists)) * nb_entitylist);
    datas->nb_entitylist = nb_entitylist;
    datas->score = 0;
    datas->clock = sfClock_create();
    init_data_storage_2(datas);
    return (datas);
}

int check_data_storage_content(data_storage_t *datas)
{
    int check = (!datas->sounds) | (!datas->sound_buffs) | (!datas->textures) |
        (!datas->entities) | (!datas->entitylists) | (!datas->clock) |
        ((!datas->window) << 1);
    int i = -1;

    if (check)
        return (check);
    while (++i < datas->nb_sounds)
        check = check | ((datas->sounds[i] == NULL) << 2);
    i = -1;
    while (++i < datas->nb_textures)
        check = check | ((datas->textures[i] == NULL) << 3);
    i = -1;
    while (++i < datas->nb_entity)
        check = check | ((datas->entities[i] == NULL) << 4);
    i = -1;
    while (++i < datas->nb_entitylist)
        check = check | ((datas->entitylists[i] == NULL) << 5);
    return (check);
}
