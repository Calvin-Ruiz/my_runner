/*
** EPITECH PROJECT, 2019
** entitylib
** File description:
** window_manager.h
*/

#ifndef WINDOW_MANAGER_H_
#define WINDOW_MANAGER_H_

int create_window(sfVideoMode mode, char *name, long int args, int fps);
void update_window(sfRenderWindow *window, internal_data_t *datas,
    data_storage_t *stor);
void destroy_window(data_storage_t *datas);
void my_pause_game(sfRenderWindow *window, data_storage_t *datas);
void my_take_screenshoot(sfRenderWindow *window, data_storage_t *datas);
void check_window_size(sfRenderWindow *window, data_storage_t *datas);

#endif /* WINDOW_MANAGER_H_ */
