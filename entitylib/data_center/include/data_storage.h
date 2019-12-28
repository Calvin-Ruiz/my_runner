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
    float coef_x;
    float coef_y;
    sfClock *clock;
    int fps;
    sfThread *displayer;
    char alive;
    player_t *player;
    sfMutex *my_lock;
    long long tref;
    long long last_refresh;
    long long last_update;
    long long coll_target;
    char **map;
    int nb_cols;
    char spacebar;
    int col;
} data_storage_t;

data_storage_t *get_data_storage(void);
data_storage_t *init_data_storage(int nb_sounds, int nb_textures,
    int nb_entity, int nb_entitylist);
int check_data_storage_content(data_storage_t *datas);
void free_storage_content(data_storage_t *datas, int mask);
void update_all(data_storage_t *datas);
void import_sound(data_storage_t *datas, const char *filename, int pos);

#endif /* DATA_STORAGE_H_ */
