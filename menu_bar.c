/*
** EPITECH PROJECT, 2019
** MUL_my_runner
** File description:
** menu_bar.c
*/
#include "include/menu_bar.h"

static void my_events(menu_bar_t *menubar, sfEvent event)
{
    sfVector2u win_size;
    int pos;

    if (event.type == sfEvtMouseButtonPressed) {
        if (!event.mouseButton.button) {
            win_size = sfRenderWindow_getSize(menubar->window);
            pos = (event.mouseButton.x * 4) / win_size.x;
            if (menubar->page)
                pos += ((event.mouseButton.y * 3) / win_size.y) * 4 + 21;
            else
                pos += ((event.mouseButton.y * 9) / win_size.y) * 4 + 1;
            menubar->select_bloc = pos;
            update_menu_bar_sprite(menubar, get_data_storage());
        } else if (event.mouseButton.button == 1)
            menubar->page = !menubar->page;
    }
}

void update_menu_bar(sfRenderWindow *win, menu_bar_t *menubar, entity_t **elist)
{
    sfEvent event;
    sfRenderWindow *window = menubar->window;
    sfVector2i pos = sfMouse_getPositionRenderWindow(win);
    sfVector2f fpos = {pos.x, pos.y};

    sfRenderWindow_clear(window, sfBlack);
    if (menubar->page)
        update_page_2(window, elist);
    else
        update_page_1(window, elist);
    sfRenderWindow_display(window);
    while (sfRenderWindow_pollEvent(window, &event))
        my_events(menubar, event);
    sfSprite_setPosition(menubar->sprite, fpos);
    sfRenderWindow_drawSprite(win, menubar->sprite, NULL);
}

menu_bar_t *create_menu_bar(sfRenderWindow *window)
{
    menu_bar_t *menubar = malloc(sizeof(menu_bar_t));

    if (menubar == NULL)
        return (NULL);
    menubar->bloc_id = get_list();
    menubar->select_bloc = 1;
    menubar->page = 0;
    menubar->window = sfRenderWindow_create((sfVideoMode) {256, 576, 32},
        "My runner toolbar", sfClose | sfResize, NULL);
    menubar->sprite = sfSprite_create();
    if (!menubar->window || !menubar->sprite)
        return (NULL);
    sfRenderWindow_setPosition(menubar->window, (sfVector2i) {0, 0});
    sfRenderWindow_setPosition(window, (sfVector2i) {260, 0});
    update_menu_bar_sprite(menubar, get_data_storage());
    return (menubar);
}

void update_menu_bar_sprite(menu_bar_t *menubar, data_storage_t *datas)
{
    sfIntRect my_rect = {0, 0, 64, 64};
    sfVector2f my_origin = {32, 32};
    sfColor my_color = {255, 255, 255, 143};

    sfSprite_setTexture(menubar->sprite,
        datas->textures[4 + menubar->select_bloc], sfFalse);
    if (menubar->select_bloc > 20) {
        my_rect.height = 192;
        my_origin.y = 96;
    }
    sfSprite_setTextureRect(menubar->sprite, my_rect);
    sfSprite_setColor(menubar->sprite, my_color);
    sfSprite_setOrigin(menubar->sprite, my_origin);
}

void destroy_menu_bar(menu_bar_t *menubar)
{
    if (sfRenderWindow_isOpen(menubar->window))
        sfRenderWindow_close(menubar->window);
    sfSprite_destroy(menubar->sprite);
    free(menubar->bloc_id);
    free(menubar);
}
