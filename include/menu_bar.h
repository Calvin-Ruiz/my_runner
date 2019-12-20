/*
** EPITECH PROJECT, 2019
** MUL_my_runner
** File description:
** menu_bar.h
*/

#ifndef MENU_BAR_H_
#define MENU_BAR_H_

#include <entitybase.h>
#include <data_storage.h>

typedef struct menu_bar {
    sfRenderWindow *window;
    sfSprite *sprite;
    char *bloc_id;
    int select_bloc;
    int page;
} menu_bar_t;

menu_bar_t *create_menu_bar(sfRenderWindow *window);
void update_menu_bar_sprite(menu_bar_t *menubar, data_storage_t *datas);
void update_menu_bar(sfRenderWindow *win, menu_bar_t *menubar,
    entity_t **elist);
void destroy_menu_bar(menu_bar_t *menubar);

static inline char *get_list()
{
    char i = -1;
    char *str = malloc(33);

    while (++i < 33)
        str[i] = (i > 7) ? i + 128 : i;
    str[2] = 130;
    str[11] = 11;
    str[12] = 12;
    return (str);
}

static inline void update_page_1(sfRenderWindow *window, entity_t **elist)
{
    sfVector2f pos = {0, 0};
    sfSprite *sprite = NULL;
    int bloc = 1;
    int x = -1;
    int y = -1;

    while (++y < 6) {
        x = -1;
        pos.x = 0;
        while (++x < 4) {
            sprite = *((elist[bloc++])->sprite);
            sfSprite_setPosition(sprite, pos);
            sfRenderWindow_drawSprite(window, sprite, NULL);
            pos.x += 64.f;
        }
        pos.y += 64.f;
    }
}

static inline void update_page_2(sfRenderWindow *window, entity_t **elist)
{
    sfVector2f pos = {0, 0};
    sfSprite *sprite = NULL;
    int bloc = 21;
    int x = -1;
    int y = -1;

    while (++y < 3) {
        x = -1;
        pos.x = 0;
        while (++x < 4) {
            sprite = *((elist[bloc++])->sprite);
            sfSprite_setPosition(sprite, pos);
            sfRenderWindow_drawSprite(window, sprite, NULL);
            pos.x += 64.f;
        }
        pos.y += 192.f;
    }
}

#endif /* MENU_BAR_H_ */
