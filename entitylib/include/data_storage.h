/*
** EPITECH PROJECT, 2019
** entitylib
** File description:
** data_storage.h
*/

#ifndef DATA_STORAGE_H_
#define DATA_STORAGE_H_

typedef struct data_storage {
    sfRenderWindow *window;
    sfSoundBuffer **sound_buffs;
    sfSound **sounds;
    int nb_sounds;
    sfTexture **textures;
    int nb_textures;
    entitylist_t **entitylists;
    int nb_entitylist;
    entity_t **entities;
    int nb_entity;
    int score;
    int higher_score;
    int health;
    float coef_x;
    float coef_y;
    sfClock *clock;
} data_storage_t;

data_storage_t *init_data_storage(int nb_sounds, int nb_textures,
    int nb_entity, int nb_entitylist);
int check_data_storage_content(data_storage_t *datas);
void free_storage_content(data_storage_t *datas, int mask);
void update_all(data_storage_t *datas);
void import_sound(data_storage_t *datas, const char *filename, int pos);

static inline data_storage_t *get_data_storage(void)
{
    static data_storage_t storage[1];
    return (storage);
}

#endif /* DATA_STORAGE_H_ */
