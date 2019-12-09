/*
** EPITECH PROJECT, 2019
** entitylib
** File description:
** data_loader.c
*/
#include <entity.h>
#include <data_storage.h>
#include <converters.h>

static void load_entity(entity_t *entity, entity_to_raw_t *data)
{
    entity->health = data->data.health;
    entity->frame_delay = data->data.frame_delay;
    entity->frame_dec = data->data.frame_dec;
    entity->frame = data->data.frame;
    entity->pos = data->data.pos;
    entity->vel = data->data.vel;
    entity->sprite += entity->frame_dec;
}

static int load_entitylist(int fd, entitylist_t *elist, data_storage_t *datas)
{
    short_to_raw_t nb_alive_entities;
    entity_to_raw_t conv;
    entity_t **entities = datas->entities;
    entity_t *tmp;
    int i = -1;
    pos_t pos = {{0, 0}, {0, 0}};

    if (read(fd, nb_alive_entities.raw, 2) != 2)
        return (84);
    while (++i < nb_alive_entities.value) {
        if (read(fd, conv.raw, sizeof(conv)) != sizeof(conv))
            return (84);
        tmp = new_instance(entities[conv.data.id_master], pos, pos.v1, 0);
        load_entity(tmp, &conv);
        elist->list[i] = tmp;
    }
    return (0);
}

int load_all(char const *filename)
{
    data_storage_t *datas = get_data_storage();
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        write(2, "Failed to open save (read mode)\n", 36);
        return (84);
    }
    data_storage_to_raw_t datas_raw;
    if (read(fd, datas_raw.raw, 4) != 4) {
        close(fd);
        return (84);
    }
    datas->score = datas_raw.data.score;
    entity_to_raw_t conv;
    if (read(fd, conv.raw, sizeof(conv)) != sizeof(conv))
        return (84);
    load_entity(datas->player->entity, &conv);
    int ret = 0;
    int i = -1;
    while (++i < datas->nb_entitylist)
        ret = ret | load_entitylist(fd, datas->entitylists[i], datas);
    close(fd);
    return (ret);
}
