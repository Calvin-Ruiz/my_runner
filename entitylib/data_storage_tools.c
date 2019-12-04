/*
** EPITECH PROJECT, 2019
** entitylib
** File description:
** data_storage_tools.c
*/
#include "include/entitylib.h"
#include "include/converters.h"

void import_sound(data_storage_t *datas, const char *filename, int i)
{
    datas->sound_buffs[i] = sfSoundBuffer_createFromFile(filename);
    if (datas->sound_buffs[i] == NULL) {
        datas->sounds[i] = NULL;
        return;
    }
    datas->sounds[i] = sfSound_create();
    if (datas->sounds[i] == NULL) {
        sfSoundBuffer_destroy(datas->sound_buffs[i]);
        datas->sound_buffs[i] = NULL;
    }
    sfSound_setBuffer(datas->sounds[i], datas->sound_buffs[i]);
}

void update_all(data_storage_t *datas)
{
    int i = -1;

    while (++i < datas->nb_entitylist)
        entitylist_updates(datas->entitylists[i]);
}

static void save_higher_score(data_storage_t *datas)
{
    int_to_raw_t conv;

    if (datas->higher_score > datas->score)
        conv.value = datas->higher_score;
    else
        conv.value = datas->score;
    int fd = open("saves/scoreboard.dat", O_WRONLY | O_CREAT, 0666);
    if (fd != -1) {
        write(fd, conv.raw, 4);
        close(fd);
    }
}

void free_storage_content(data_storage_t *datas, int mask)
{
    int i = -1;

    while (++i < datas->nb_sounds && (mask & 4))
        if (datas->sounds[i] != NULL) {
            sfSound_destroy(datas->sounds[i]);
            sfSoundBuffer_destroy(datas->sound_buffs[i]);
        }
    i = -1;
    while (++i < datas->nb_textures && (mask & 8))
        if (datas->textures[i] != NULL)
            sfTexture_destroy(datas->textures[i]);
    i = -1;
    while (++i < datas->nb_entity && (mask & 16))
        free_entity(datas->entities[i]);
    i = -1;
    while (++i < datas->nb_entitylist && (mask & 32))
        destroy_entitylist(datas->entitylists[i]);
    if (datas->window != NULL && (mask & 2))
        destroy_window(datas);
    save_higher_score(datas);
}
