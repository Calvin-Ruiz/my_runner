/*
** EPITECH PROJECT, 2019
** entitylib
** File description:
** collider.c
*/
#include <entitybase.h>
#include <data_storage.h>
#include <collider.h>

collider_t *get_collider_data(void)
{
    static collider_t data[1];
    return (data);
}

static void collide_and_update_all(collider_t *data)
{
    const long long frame_delay = data->frame_delay;
    sfClock *clock = data->data_clock;
    long long *actual = &(get_data_storage()->last_update);
    long long *target = &(get_data_storage()->coll_target);
    long int nb_loops = 0;

    *target = sfClock_getElapsedTime(clock).microseconds;
    while (data->alive) {
        *target += frame_delay;
        collide_solid_static(data);
        collide_solid_dynamic(data);
        collide_fired(data);
        collide_mob(data);
        collide_player(data);
        *actual = sfClock_getElapsedTime(clock).microseconds;
        if (*target > *actual)
            sfSleep((sfTime) {*target - *actual});
        nb_loops++;
    }
    data->time_lost_per_frame = (*actual - *target) / nb_loops;
}

static void init_collider_datas(int *pos, data_storage_t *datas,
    collider_t *data, long long fps)
{
    data->frame_delay = 1000000 / fps;
    if (data->nb_solid_static)
        *data->solid_static = datas->entitylists[pos[0]];
    if (data->nb_solid_dynamic)
        *data->solid_dynamic = datas->entitylists[pos[1]];
    if (data->nb_hollow_static)
        *data->hollow_static = datas->entitylists[pos[2]];
    if (data->nb_hollow_dynamic)
        *data->hollow_dynamic = datas->entitylists[pos[3]];
    if (data->nb_fired)
        *data->fired = datas->entitylists[pos[4]];
    if (data->nb_mob)
        *data->mob = datas->entitylists[pos[5]];
    data->player = datas->player->entity;
    data->data_clock = datas->clock;
    data->my_scroll.x = -256.f;
    data->my_scroll.y = 0.f;
    datas->my_lock = sfMutex_create();
}

int init_collider(int *pos, int *sizes, data_storage_t *datas, long long fps)
{
    collider_t *data = get_collider_data();
    data->nb_solid_static = sizes[0];
    data->solid_static = malloc(sizeof(void *) * data->nb_solid_static);
    data->nb_solid_dynamic = sizes[1];
    data->solid_dynamic = malloc(sizeof(void *) * data->nb_solid_dynamic);
    data->nb_hollow_static = sizes[2];
    data->hollow_static = malloc(sizeof(void *) * data->nb_hollow_static);
    data->nb_hollow_dynamic = sizes[3];
    data->hollow_dynamic = malloc(sizeof(void *) * data->nb_hollow_dynamic);
    data->nb_fired = sizes[4];
    data->fired = malloc(sizeof(void *) * data->nb_fired);
    data->nb_mob = sizes[5];
    data->mob = malloc(sizeof(void *) * data->nb_mob);
    init_collider_datas(pos, datas, data, fps);
    data->alive = 1;
    data->updater = sfThread_create((void (*)(void *)) collide_and_update_all, data);
    if (data->updater == NULL)
        return (84);
    sfThread_launch(data->updater);
    return (0);
}

void destroy_collider(void)
{
    collider_t *data = get_collider_data();

    data->alive = 0;
    sfThread_destroy(data->updater);
    free(data->solid_static);
    free(data->solid_dynamic);
    free(data->hollow_static);
    free(data->hollow_dynamic);
    free(data->fired);
    free(data->mob);
}
