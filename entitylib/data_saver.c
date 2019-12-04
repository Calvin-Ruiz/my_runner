/*
** EPITECH PROJECT, 2019
** entitylib
** File description:
** data_saver.c
*/
#include "include/entitybase.h"
#include "include/data_storage.h"
#include "include/converters.h"

static void save_entity(int fd, entity_t *entity, entity_t **entities)
{
    entity_to_raw_t conv;
    short id_master = -1;

    while (entity->size != entities[++id_master]->size);
    conv.data.id_master = id_master;
    conv.data.health = entity->health;
    conv.data.frame_delay = entity->frame_delay;
    conv.data.frame_dec = entity->frame_dec;
    conv.data.frame = entity->frame;
    conv.data.pos = entity->pos;
    conv.data.vel = entity->vel;
    write(fd, conv.raw, sizeof(conv.data));
}

static void save_entitylist(int fd, entitylist_t *elist, entity_t **entities)
{
    int i = -1;
    short_to_raw_t nbr_alive_entities;

    nbr_alive_entities.value = 0;
    while (++i < elist->len)
        nbr_alive_entities.value += (elist->list[i] != NULL);
    write(fd, nbr_alive_entities.raw, 2);
    i = -1;
    while (++i < elist->len) {
        if (elist->list[i] != NULL)
            save_entity(fd, elist->list[i], entities);
    }
}

int save_all(const char *filename)
{
    data_storage_t *datas = get_data_storage();
    entity_t **entities = datas->entities;
    entitylist_t **elists = datas->entitylists;
    int fd = open(filename, O_WRONLY | O_CREAT, 0666);

    if (fd == -1) {
        write(2, "Failed to open save (write mode)\n", 37);
        return (84);
    }
    data_storage_to_raw_t datas_raw;
    datas_raw.data.score = datas->score;
    datas_raw.data.health = datas->health;
    write(fd, datas_raw.raw, 8);
    int i = -1;
    while (++i < datas->nb_entitylist)
        save_entitylist(fd, elists[i], entities);
    close(fd);
    return (0);
}
