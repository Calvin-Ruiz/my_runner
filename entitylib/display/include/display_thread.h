/*
** EPITECH PROJECT, 2019
** entitylib
** File description:
** display_thread.h
*/

#ifndef DISPLAY_THREAD_H_
#define DISPLAY_THREAD_H_

void my_displayer(void *ptr);

static inline void destroy_displayer(data_storage_t *datas)
{
    sfThread_wait(datas->displayer);
    sfThread_destroy(datas->displayer);
    sfMutex_destroy(datas->my_lock);
}

static inline void stop_displayer(data_storage_t *datas)
{
    sfThread_wait(datas->displayer);
    sfMutex_destroy(datas->my_lock);
}

#endif /* DISPLAY_THREAD_H_ */
