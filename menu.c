/*
** EPITECH PROJECT, 2019
** MUL_my_runner
** File description:
** menu.c
*/

#include "include/main.h"

static void my_clic(data_storage_t *datas, sfEvent event, param_t *params,
    char *is_opened)
{
    int y = event.mouseButton.y * sfRenderWindow_getSize(datas->window).y / 768;

    if (event.mouseButton.button == 0 && event.mouseButton.x < 842
        && event.mouseButton.x > 440) {
        if (y > 55 && y < 257) {
            params->editor = 0;
            *is_opened = 0;
        } else if (y > 283 && y < 485) {
            params->editor = 1;
            *is_opened = 0;
        }
    }
    datas->spacebar = 0;
}

static int my_events(param_t *params, char ***map, int nb_cols, char *is_opened)
{
    sfEvent event;
    data_storage_t *datas = get_data_storage();

    sfSleep((sfTime) {20000});
    while (*is_opened && sfRenderWindow_pollEvent(datas->window, &event)) {
        if (event.type == sfEvtClosed) {
            *is_opened = 0;
            sfRenderWindow_close(datas->window);
        } else if (event.type == sfEvtMouseButtonPressed)
            my_clic(datas, event, params, is_opened);
    }
    return (nb_cols);
}

int my_menu(param_t *params, char ***map, int nb_cols)
{
    char is_opened = 1;
    data_storage_t *datas = get_data_storage();
    sfRenderWindow *window = datas->window;
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile("textures/menu.png", NULL);
    if (sprite == NULL || texture == NULL)
        return (nb_cols);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, (sfVector2f) {1, ((float) (**map)[-1]) / 12.f});
    sfRenderWindow_setMouseCursorVisible(window, sfTrue);
    while (is_opened) {
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_display(window);
        nb_cols = my_events(params, map, nb_cols, &is_opened);
    }
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
    *map = datas->map;
    return (nb_cols);
}

int my_submenu(param_t *params, char ***map, int nb_cols)
{
    data_storage_t *datas = get_data_storage();
}
