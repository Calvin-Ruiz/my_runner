/*
** EPITECH PROJECT, 2019
** entitylib
** File description:
** window_manager.c
*/
#include <entitybase.h>
#include <internal_data.h>
#include <data_storage.h>
#include <base_collider.h>
#include <display_thread.h>

static int create_backgrounds(internal_data_t *datas, data_storage_t *stor)
{
    const sfVector2f scale = {1.f, ((float) stor->map[0][-1]) / 12.f};
    sfIntRect rect = {0, 0, 2560, 768};
    datas->background = sfSprite_create();
    datas->background2 = sfSprite_create();
    datas->background3 = sfSprite_create();
    if (datas->background_skin == NULL || datas->background == NULL
        || datas->background2 == NULL || datas->background3 == NULL)
        return (84);
    sfSprite_setTexture(datas->background, datas->background_skin, sfTrue);
    sfSprite_setTextureRect(datas->background, rect);
    sfSprite_setScale(datas->background, scale);
    rect.top += 768;
    sfSprite_setTexture(datas->background2, datas->background_skin, sfTrue);
    sfSprite_setTextureRect(datas->background2, rect);
    sfSprite_setScale(datas->background2, scale);
    rect.top += 768;
    sfSprite_setTexture(datas->background3, datas->background_skin, sfTrue);
    sfSprite_setTextureRect(datas->background3, rect);
    sfSprite_setScale(datas->background3, scale);
    return (0);
}

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
    if (create_backgrounds(datas, stor))
        return (84);
    stor->background1_pos = (sfVector2f) {0.f, 0.f};
    stor->background2_pos = (sfVector2f) {0.f, 0.f};
    stor->background3_pos = (sfVector2f) {0.f, 0.f};
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
    stor->fps = fps;
    stor->displayer = sfThread_create(my_displayer, stor);
    stor->alive = 1;
    stor->window = sfRenderWindow_create(mode, name, args, NULL);
    datas->cursor = sfSprite_create();
    datas->pause = sfSprite_create();
    datas->cursor_skin = sfTexture_createFromFile("textures/cursor.png", NULL);
    datas->pause_skin = sfTexture_createFromFile("textures/pause.png", NULL);
    if (!stor->window || !datas->cursor || !datas->pause || !datas->cursor_skin
        || !datas->pause_skin || !stor->displayer)
        return (84);
    stor->view = sfView_copy(sfRenderWindow_getView(stor->window));
    sfRenderWindow_setFramerateLimit(stor->window, fps);
    sfRenderWindow_setMouseCursorVisible(stor->window, sfFalse);
    sfRenderWindow_setView(stor->window, stor->view);
    sfSprite_setTexture(datas->pause, datas->pause_skin, sfFalse);
    sfSprite_setTexture(datas->cursor, datas->cursor_skin, sfTrue);
    return (create_window_2(datas, stor));
}

void destroy_window(data_storage_t *stor)
{
    internal_data_t *datas = get_internal_data();

    sfTexture_destroy(datas->cursor_skin);
    sfTexture_destroy(datas->pause_skin);
    sfTexture_destroy(datas->background_skin);
    sfSprite_destroy(datas->cursor);
    sfSprite_destroy(datas->pause);
    sfSprite_destroy(datas->background);
    sfSprite_destroy(datas->background2);
    sfSprite_destroy(datas->background3);
    sfImage_destroy(datas->icon);
    sfRenderWindow_destroy(stor->window);
}

void update_window(sfRenderWindow *window, internal_data_t *datas,
    data_storage_t *stor)
{
    sfVector2i pointer = sfMouse_getPositionRenderWindow(window);
    sfVector2u size = sfRenderWindow_getSize(window);

    if (size.x < 800 || size.x > 1920)
        size.x = (size.x < 800) ? 800 : 1920;
    if (size.y < 600 || size.y > 1080)
        size.y = (size.y < 600) ? 600 : 1080;
    sfRenderWindow_setSize(window, size);
    stor->coef_x = 1280.f / size.x;
    stor->coef_y = (64.f * stor->map[0][-1]) / size.y;
    sfSprite_setPosition(datas->cursor,
        (sfVector2f) {pointer.x * stor->coef_x, pointer.y * stor->coef_y});
    sfRenderWindow_drawSprite(window, datas->cursor, NULL);
    sfRenderWindow_display(window);
    sfSprite_setPosition(datas->background, stor->background1_pos);
    sfRenderWindow_drawSprite(window, datas->background, NULL);
    sfSprite_setPosition(datas->background2, stor->background2_pos);
    sfRenderWindow_drawSprite(window, datas->background2, NULL);
    sfSprite_setPosition(datas->background3, stor->background3_pos);
    sfRenderWindow_drawSprite(window, datas->background3, NULL);
}
