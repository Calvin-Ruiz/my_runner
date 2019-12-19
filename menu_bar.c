/*
** EPITECH PROJECT, 2019
** MUL_my_runner
** File description:
** menu_bar.c
*/
#include "include/menu_bar.h"

menu_bar_t *create_menu_bar(void)
{
    menu_bar_t *menubar = malloc(sizeof(menu_bar_t));
    char list[] = {0, 1, 2, 3 + 128, 4, 5 + 128, 6 + 128};
    int i = -1;

    menubar->bloc_id = malloc(64);
    while (++i < sizeof(list))
        menubar->bloc_id[i] = list[i];
    while (i < 64) {
        menubar->bloc_id[i++] = 0;
    }
    menubar->select_bloc = 0;
    return (menubar);
}
