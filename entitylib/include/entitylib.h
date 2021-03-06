/*
** EPITECH PROJECT, 2019
** entitylib
** File description:
** entitylib.h
*/

#ifndef ENTITYLIB_H_
#define ENTITYLIB_H_

#include <entity.h>
#include <entitylist.h>
#include <data_storage.h>
#include <internal_data.h>
#include <window_manager.h>
#include <base_collider.h>
#include <entity_types.h>

void apply_all(entitylist_t *self, void (*action)(), void *arg);
void apply_all_custom(entitylist_t *self, void *args);
uint_t *get_size(uint_t width, uint_t height, uint_t nbr_rows);
sfVector2f *get_pos(float x, float y);
float *get_vel(float x, float y);
void my_game_over(sfRenderWindow *window, internal_data_t *datas,
    data_storage_t *stor, sfSprite *sprite);
void my_write_score(char *str1, char *str2, data_storage_t *datas);
void display_health_and_score(sfRenderWindow *window, data_storage_t *stor,
    internal_data_t *datas);
int init_heart_and_score(sfTexture *heart, sfTexture *end_texture);
void destroy_heart_and_score(void);
int load_music(data_storage_t *data, const char *filename);
void update_volume(data_storage_t *data);

#endif /* ENTITYLIB_H_ */
