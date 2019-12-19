/*
** EPITECH PROJECT, 2019
** MUL_my_runner
** File description:
** menu_bar.h
*/

#ifndef MENU_BAR_H_
#define MENU_BAR_H_

#include <entitybase.h>

typedef struct menu_bar {
    char *bloc_id;
    int select_bloc;
} menu_bar_t;

menu_bar_t *create_menu_bar(void);

#endif /* MENU_BAR_H_ */
