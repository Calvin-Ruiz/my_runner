/*
** EPITECH PROJECT, 2019
** entitylib
** File description:
** window_manager.c
*/
#include "include/entitybase.h"
#include "include/internal_data.h"
#include "include/data_storage.h"

static int create_window_2(internal_data_t *datas, data_storage_t *stor)
{
    datas->icon = sfImage_createFromFile("textures/icon.png");
    if (datas->icon == NULL)
        return (84);
    sfVector2f vector;
    sfVector2u size = sfImage_getSize(datas->icon);
    const sfUint8 *icon = sfImage_getPixelsPtr(datas->icon);

    sfRenderWindow_setIcon(stor->window, size.x, size.y, icon);
    datas->background_skin = sfTexture_createFromFile("textures/background.png",
        NULL);
    datas->fullscreen = 0;
    datas->background = sfSprite_create();
    if (datas->background_skin == NULL || datas->background == NULL)
        return (84);
    sfSprite_setTexture(datas->background, datas->background_skin, sfTrue);
    sfVector2u pos = sfTexture_getSize(datas->cursor_skin);
    vector.x = pos.x / 2;
    vector.y = pos.y / 2;
    sfSprite_setOrigin(datas->cursor, vector);
    return (0);
}

int create_window(sfVideoMode mode, char *name, long int args, int fps)
{
    data_storage_t *stor = get_data_storage();
    internal_data_t *datas = get_internal_data();
    stor->window = sfRenderWindow_create(mode, name, args, NULL);
    datas->cursor = sfSprite_create();
    datas->pause = sfSprite_create();
    datas->cursor_skin = sfTexture_createFromFile("textures/cursor.png", NULL);
    datas->pause_skin = sfTexture_createFromFile("textures/pause.png", NULL);
    if (!stor->window || !datas->cursor || !datas->pause || !datas->cursor_skin
        || !datas->pause_skin)
        return (84);
    sfRenderWindow_setFramerateLimit(stor->window, fps);
    sfRenderWindow_setMouseCursorVisible(stor->window, sfFalse);
    sfRenderWindow_setMouseCursorGrabbed(stor->window, sfTrue);
    sfSprite_setTexture(datas->pause, datas->pause_skin, sfFalse);
    sfSprite_setTexture(datas->cursor, datas->cursor_skin, sfTrue);
    return (create_window_2(datas, stor));
}

void destroy_window(data_storage_t *stor)
{
    internal_data_t *datas = get_internal_data();

    sfRenderWindow_destroy(stor->window);
    sfTexture_destroy(datas->cursor_skin);
    sfTexture_destroy(datas->pause_skin);
    sfSprite_destroy(datas->cursor);
    sfSprite_destroy(datas->pause);
    sfImage_destroy(datas->icon);
}

void update_window(sfRenderWindow *window, internal_data_t *datas,
    data_storage_t *stor)
{
    sfVector2i pointer = sfMouse_getPositionRenderWindow(window);
    sfVector2u size = sfRenderWindow_getSize(window);
    sfVector2f fpointer;

    if (size.x < 800 || size.x > 1920)
        size.x = (size.x < 800) ? 800 : 1920;
    if (size.y < 600 || size.y > 1080)
        size.y = (size.y < 600) ? 600 : 1080;
    sfRenderWindow_setSize(window, size);
    stor->coef_x = 1600.f / size.x;
    stor->coef_y = 800.f / size.y;
    fpointer.x = pointer.x * stor->coef_x;
    fpointer.y = pointer.y * stor->coef_y;
    sfSprite_setPosition(datas->cursor, fpointer);
    sfRenderWindow_drawSprite(window, datas->cursor, NULL);
    sfRenderWindow_display(window);
    sfRenderWindow_drawSprite(window, datas->background, NULL);
}
