/*
** EPITECH PROJECT, 2019
** MUL_my_runner
** File description:
** main.c
*/
#include "include/main.h"

static void my_help(int n, char **args)
{
    if (n != 2 || args[1][0] != '-' || args[1][1] != 'h' || args[1][2] != '\0')
        return;
    int fd = open("readme.txt", O_RDONLY);
    if (fd == -1) {
        write(2, "Help unavailable : file 'readme.txt' not found.\n", 48);
        return;
    }
    long int len = 0;
    char *str = my_read(fd, &len);
    close(fd);
    if (str == NULL) {
        write(2, "Help unavailable : read error\n", 30);
        return;
    }
    write(1, str, len);
    free(str);
}

static void my_events(sfRenderWindow *window, data_storage_t *datas)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
            my_pause_game(window, datas);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyF12)
            my_take_screenshoot(window, datas);
    }
}

void mainloop(data_storage_t *datas)
{
    sfRenderWindow *window = datas->window;
    while (sfRenderWindow_isOpen(datas->window)) {
        my_events(window, datas);
    }
}

static int my_init_entities(data_storage_t *datas)
{
    datas->entitylists[0] = create_entitylist(128);
    datas->entitylists[1] = create_entitylist(32);
    datas->entitylists[2] = create_entitylist(32);
    datas->entitylists[3] = create_entitylist(32);
    datas->entitylists[4] = create_entitylist(16);
    datas->entitylists[5] = create_entitylist(16);
    if (!check_data_storage_content(datas))
        return (0);
    free_storage_content(datas, 63);
    return (84);
}

static int my_init(char **map, param_t *params, int nb_cols, long int len)
{
    data_storage_t *datas = init_data_storage(0, 2, 0, 6);
    if (create_window((sfVideoMode) {1280, 64 * (*map)[-1], 32}, "My Runner",
        sfClose | sfResize, params->fps))
        return (84);
    datas->textures[0] = sfTexture_createFromFile("textures/end.png", NULL);
    datas->textures[1] = sfTexture_createFromFile("textures/heart.png", NULL);
    if (check_data_storage_content(datas) & 11) {
        if ((check_data_storage_content(datas) & 1) == 0)
            free_storage_content(datas, 11);
        return (84);
    }
    if (my_init_entities(datas))
        return (84);
    int sizes[6] = {1, 1, 1, 1, 1, 1};
    int pos[6] = {0, 1, 2, 3, 4, 5};
    if (init_collider(pos, sizes, datas))
        return (84);
    return (my_init_uninit(map, params, nb_cols, len));
}

int main(int nargs, char **args)
{
    int i = 0;
    param_t params[1];
    *params = (param_t) {60, '\0' + 1, '\0', '\0', 0, '\0', 0};
    my_help(nargs, args);
    while (++i < nargs) {
        if (args[i][0] == '-')
            i = apply_parameter(i, args, params);
        else
            params->name = args[i];
    }
    params->editor = params->editor | params->nb_lines;
    params->menu = params->menu | !(params->practice | params->editor);
    long int len = 0;
    int nb_cols = 0;
    char **map = load_map(params->name, &len, &nb_cols);
    if (map == NULL)
        return (84);
    int exit_mode = my_init(map, params, nb_cols, len);
    return (exit_mode);
}
