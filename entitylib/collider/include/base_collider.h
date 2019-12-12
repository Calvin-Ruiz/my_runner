/*
** EPITECH PROJECT, 2019
** entitylib
** File description:
** base_collider.h
*/

#ifndef BASE_COLLIDER_H_
#define BASE_COLLIDER_H_

typedef struct collider_data {
    entitylist_t **solid_static;
    int nb_solid_static;
    entitylist_t **solid_dynamic;
    int nb_solid_dynamic;
    entitylist_t **hollow_static;
    int nb_hollow_static;
    entitylist_t **hollow_dynamic;
    int nb_hollow_dynamic;
    entitylist_t **fired;
    int nb_fired;
    entitylist_t **mob;
    int nb_mob;
    entity_t *player;
    sfThread *updater;
    sfVector2f my_scroll;
    sfClock *data_clock;
    int alive;
    long long frame_delay;
    long long time_lost_per_frame;
} collider_t;

collider_t *get_collider_data(void);
int init_collider(int *pos, int *sizes, data_storage_t *datas, long long fps);
void destroy_collider(void);

#endif /* BASE_COLLIDER_H_ */
