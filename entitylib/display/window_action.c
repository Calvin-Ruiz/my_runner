/*
** EPITECH PROJECT, 2019
** entitylib
** File description:
** window_action.c
*/
#include <entitybase.h>
#include <data_storage.h>
#include <internal_data.h>
#include <converters.h>
#include <window_manager.h>

static void my_save_screenshoot(sfImage *image)
{
    int fd = open("saves/nbr_screenshoots.dat", O_RDONLY);
    int_to_raw_t nbr_screenshoots;

    if (fd != -1) {
        int size = read(fd, nbr_screenshoots.raw, 4);
        nbr_screenshoots.value = (size == 4) ? nbr_screenshoots.value + 1 : 1;
        close(fd);
    } else
        nbr_screenshoots.value = 1;
    fd = open("saves/nbr_screenshoots.dat", O_WRONLY | O_CREAT, 0666);
    write(fd, nbr_screenshoots.raw, 4);
    close(fd);
    char name[] = "screenshoots/screenshoot_0000.png";
    char *str = name + 28;

    while (nbr_screenshoots.value > 0) {
        *(str--) += nbr_screenshoots.value % 10;
        nbr_screenshoots.value /= 10;
    }
    sfImage_saveToFile(image, name);
}

void my_take_screenshoot(sfRenderWindow *window, data_storage_t *datas)
{
    sfVector2u size = sfRenderWindow_getSize(window);
    sfTexture *texture = sfTexture_create(size.x, size.y);

    if (texture == NULL)
        return;
    sfTexture_updateFromRenderWindow(texture, window, 0, 0);
    sfMutex_unlock(datas->my_lock);
    sfImage *image = sfTexture_copyToImage(texture);

    if (image == NULL) {
        sfTexture_destroy(texture);
        return;
    }
    my_save_screenshoot(image);
    sfTexture_destroy(texture);
    sfImage_destroy(image);
    sfMutex_lock(datas->my_lock);
}

static void my_pause_loop(sfRenderWindow *window, data_storage_t *datas)
{
    sfEvent event;

    while (sfRenderWindow_isOpen(window)) {
        if (sfRenderWindow_pollEvent(window, &event) &&
            (event.type == sfEvtKeyPressed ||
            event.type == sfEvtMouseButtonPressed))
            break;
        while (sfRenderWindow_pollEvent(window, &event));
        check_window_size(window, datas);
        sfRenderWindow_display(window);
        sfRenderWindow_setMouseCursorGrabbed(window, sfFalse);
    }
}

void my_pause_game(sfRenderWindow *window, data_storage_t *stor)
{
    sfClock *my_clock = sfClock_create();
    internal_data_t *datas = get_internal_data();

    sfRenderWindow_drawSprite(window, datas->pause, NULL);
    sfRenderWindow_setMouseCursorVisible(window, sfTrue);
    sfRenderWindow_display(window);
    my_pause_loop(window, stor);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    stor->tref += sfClock_getElapsedTime(my_clock).microseconds;
    sfClock_destroy(my_clock);
}

void check_window_size(sfRenderWindow *window, data_storage_t *datas)
{
    sfVector2u size = sfRenderWindow_getSize(window);

    if (size.x < 800 || size.x > 1920)
        size.x = (size.x < 800) ? 800 : 1920;
    if (size.y < 600 || size.y > 1080)
        size.y = (size.y < 600) ? 600 : 1080;
    datas->coef_x = 1280.f / size.x;
    datas->coef_y = (64.f * datas->map[0][-1]) / size.y;
    sfRenderWindow_setSize(window, size);
}
