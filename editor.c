/*
** EPITECH PROJECT, 2019
** MUL_my_runner
** File description:
** editor.c
*/
#include "include/editor.h"
#include "include/menu_bar.h"
#include <window_manager.h>

static void display_all(sfRenderWindow *window, data_storage_t *datas, int col,
    const char nb_lines)
{
    const int col_max = (col + 21 < datas->nb_cols) ? col + 21 : datas->nb_cols;
    char pos = -1;
    sfVector2f vec = {0.f, 0.f};

    while (++col < col_max) {
        vec.y = 0.f;
        pos = -1;
        while (++pos < nb_lines) {
            display_bloc(window, datas->map[col][pos], vec, datas);
            vec.y += 64.f;
        }
        vec.x += 64.f;
    }
}

static void my_events(sfRenderWindow *window, data_storage_t *datas, int *col,
    menu_bar_t *menubar)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
            return;
        }
        if (event.type == sfEvtKeyPressed)
            event_press(event, col);
        if (event.type == sfEvtMouseButtonPressed)
            mouse_press(event, menubar, datas, *col);
        if (event.type == sfEvtMouseWheelScrolled)
            mouse_wheel(event, menubar);
    }
}

static int my_opener(const char *filename)
{
    char *begin = "level/";
    int name_len = -1;
    char *full_path;
    int fd;
    int i = -1;

    if (filename == NULL)
        return (-1);
    while (filename[++name_len] != '\0');
    filename -= 6;
    name_len += 7;
    full_path = malloc(name_len);
    while (++i < 6)
        full_path[i] = begin[i];
    i--;
    while (++i < name_len)
        full_path[i] = filename[i];
    fd = open(full_path, O_WRONLY | O_CREAT, 0666);
    free(full_path);
    return (fd);
}

static void save_map(char **map, int nb_cols, const char *filename,
    data_storage_t *datas)
{
    const char nb_lines = map[0][-1];
    int i = -1;
    int fd = my_opener(filename);
    int name_len = -1;

    if (fd == -1) {
        write(2, "Error : unable to write in file 'level/", 39);
        while (filename[++name_len] != '\0');
        write(2, filename, name_len);
        write(2, "'\n", 2);
    } else {
        write(fd, map[0] - 1, 1);
        while (++i < datas->nb_cols)
            write(fd, map[i], nb_lines);
        close(fd);
    }
}

int map_editor(char **map, int nb_cols, int nb_lines_param,
    const char *filename)
{
    data_storage_t *datas = get_data_storage();
    internal_data_t *data = get_internal_data();
    sfRenderWindow *window = datas->window;
    const char nb_lines = map[0][-1];
    int col = 0;
    menu_bar_t *menubar = create_menu_bar();

    sfRenderWindow_setMouseCursorVisible(window, sfTrue);
    datas->map = map;
    datas->nb_cols = nb_cols;
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_drawSprite(window, data->background, NULL);
        display_all(window, datas, col - 1, nb_lines);
        sfRenderWindow_display(window);
        check_window_size(window, datas);
        my_events(window, datas, &col, menubar);
    }
    save_map(datas->map, nb_cols, filename, datas);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    return (nb_cols);
}
