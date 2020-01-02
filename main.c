/*
** EPITECH PROJECT, 2019
** MUL_my_runner
** File description:
** main.c
*/
#include "include/main.h"

int my_init_uninit(char **map, int nb_cols, param_t *params)
{
    data_storage_t *datas = get_data_storage();
    int return_value = 0;

    if (sfRenderWindow_isOpen(datas->window)) {
        if (params->menu) {
            write(1, "No menu\n", 8);
        } else if (params->editor)
            nb_cols = map_editor(map, nb_cols, params->nb_lines, params->name);
        else
            return_value = my_play(map, nb_cols);
        params->menu = !params->menu;
        if (return_value || my_init_uninit(datas->map, nb_cols, params))
            return (84);
    } else {
        free_storage_content(datas, 63);
        free(*map - 1);
        free(map);
        sfMusic_destroy(datas->music);
    }
    return (0);
}

static void my_init_textures(data_storage_t *datas)
{
    int fd = open("textures/bloclist.txt", O_RDONLY);
    char *filename;
    int i = 0;
    internal_data_t *dat = get_internal_data();

    if (fd == -1) {
        datas->textures[0] = NULL;
        return;
    }
    filename = fast_get_next_line(fd);
    while (filename && *filename) {
        datas->textures[i++] = sfTexture_createFromFile(filename, NULL);
        filename = fast_get_next_line(fd);
    }
    close(fd);
    dat->level_completed_skin = sfTexture_createFromFile("textures/won.png", 0);
    dat->level_completed = sfSprite_create();
    if (dat->level_completed_skin && dat->level_completed)
        sfSprite_setTexture(dat->level_completed, dat->level_completed_skin,
            sfFalse);
}

static int my_init_entities(data_storage_t *datas)
{
    datas->entitylists[0] = create_entitylist(96);
    datas->entitylists[1] = create_entitylist(16);
    datas->entitylists[2] = create_entitylist(160);
    datas->entitylists[3] = create_entitylist(32);
    datas->entitylists[4] = create_entitylist(8);
    datas->entitylists[5] = create_entitylist(4);
    my_init_entity_bases(datas);
    entitylist_append(datas->entitylists[4], new_instance(
        datas->entities[datas->nb_entity - 2],
        (pos_t) {(sfVector2f) {-80.f, 0}, (sfVector2f) {0, 0}},
        (sfVector2f) {25.6f, 0}, 0));
    load_music(datas, "sounds/background_music.ogg");
    import_sound(datas, "sounds/jump.flac", 0);
    if (!check_data_storage_content(datas))
        return (0);
    free_storage_content(datas, 63);
    return (84);
}

static int my_init(char **map, param_t *params, int nb_cols)
{
    data_storage_t *datas = init_data_storage(1, 39, 64, 6);

    if (create_window((sfVideoMode) {1280, 64 * (*map)[-1], 32},
        "My Runner", sfClose | sfResize, params->fps))
        return (84);
    if (params->fen_size.x != 0)
        sfRenderWindow_setSize(datas->window, params->fen_size);
    my_init_textures(datas);
    sfSprite_setScale(get_internal_data()->level_completed,
        (sfVector2f) {1, ((float) (*map)[-1]) / 12.f});
    if (check_data_storage_content(datas) & 11) {
        if ((check_data_storage_content(datas) & 1) == 0)
            free_storage_content(datas, 11);
        return (84);
    }
    if (my_init_entities(datas))
        return (84);
    datas->player = create_player((*map)[-1]);
    datas->player->entity->vel.x = 25.6f;
    return (my_init_uninit(map, nb_cols, params));
}

int main(int nargs, char **args)
{
    int i = 0;
    param_t params[1] = {(param_t) {60, 1, 0, 0, 0, 0, 0, (sfVector2u) {0, 0}}};
    long int len = 0;
    int nb_cols = 0;
    char **map;

    my_help(nargs, args);
    while (++i < nargs) {
        if (args[i][0] == '-')
            i = apply_parameter(i, args, params);
        else if (i < nargs)
            params->name = args[i];
    }
    params->editor = params->editor || params->nb_lines;
    params->menu = params->menu & !(params->practice | params->editor);
    map = load_map(params->name, &len, &nb_cols, params->nb_lines);
    if (map == NULL)
        return (84);
    get_data_storage()->map = map;
    return (my_init(map, params, nb_cols));
}
