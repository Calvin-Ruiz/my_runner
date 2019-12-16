/*
** EPITECH PROJECT, 2019
** MUL_my_runner
** File description:
** main.c
*/
#include "include/main.h"

static void my_help(int n, char **args)
{
    int fd;
    char *str;
    long int len = 0;

    if (n != 2 || args[1][0] != '-' || args[1][1] != 'h' || args[1][2] != '\0')
        return;
    fd = open("readme.txt", O_RDONLY);
    if (fd == -1) {
        write(2, "Help unavailable : file 'readme.txt' not found.\n", 48);
        return;
    }
    str = my_read(fd, &len);
    close(fd);
    if (str == NULL) {
        write(2, "Help unavailable : read error\n", 30);
        return;
    }
    write(1, str, len);
    free(str);
}

static void my_init_textures(data_storage_t *datas)
{
    datas->textures[0] = sfTexture_createFromFile("textures/end.png", NULL);
    datas->textures[1] = sfTexture_createFromFile("textures/heart.png", NULL);
    datas->textures[2] = sfTexture_createFromFile("textures/player.png", NULL);
    datas->textures[3] = sfTexture_createFromFile("textures/ground.png", NULL);
    datas->textures[4] = sfTexture_createFromFile("textures/jumper.png", NULL);
    datas->textures[5] = sfTexture_createFromFile("textures/barrier.png", NULL);
}

static void my_init_entity_bases(data_storage_t *datas)
{
    datas->entities[0] = create_player_entity(datas->textures[2],
        get_size(64, 128, 3), 0.15f, 10);
    datas->entities[1] = create_surface(datas->textures[3], get_size(64, 64, 1),
        0.2f, no_custom);
    datas->entities[2] = create_surface(datas->textures[4], get_size(64, 64, 1),
        0.2f, my_jump);
    datas->entities[3] = create_fired(datas->textures[5],
        get_size(1, 64 * 32, 1), 2.f, 1073741824);
    datas->entities[3]->custom = my_barrier;
}

static int my_init_entities(data_storage_t *datas)
{
    datas->entitylists[0] = create_entitylist(128);
    datas->entitylists[1] = create_entitylist(32);
    datas->entitylists[2] = create_entitylist(32);
    datas->entitylists[3] = create_entitylist(32);
    datas->entitylists[4] = create_entitylist(16);
    datas->entitylists[5] = create_entitylist(16);
    my_init_entity_bases(datas);
    entitylist_append(datas->entitylists[4], new_instance(datas->entities[3],
        (pos_t) {(sfVector2f) {-64.f, 0}, (sfVector2f) {0, 0}},
        (sfVector2f) {25.6f, 0}, 0));
    if (!check_data_storage_content(datas))
        return (0);
    free_storage_content(datas, 63);
    return (84);
}

static int my_init(char **map, param_t *params, int nb_cols, long int len)
{
    data_storage_t *datas = init_data_storage(0, 6, 4, 6);
    int tmp = create_window((sfVideoMode) {1280, 64 * (*map)[-1], 32},
        "My Runner", sfClose | sfResize, params->fps);

    if (tmp)
        return (84);
    my_init_textures(datas);
    if (check_data_storage_content(datas) & 11) {
        if ((check_data_storage_content(datas) & 1) == 0)
            free_storage_content(datas, 11);
        return (84);
    }
    if (my_init_entities(datas))
        return (84);
    datas->player = create_player((*map)[-1]);
    datas->player->entity->vel.x = 25.6f;
    return (my_init_uninit(map, params, nb_cols, len));
}

int main(int nargs, char **args)
{
    int i = 0;
    param_t params[1] = {(param_t) {60, '\0' + 1, '\0', '\0', 0, '\0', 0}};
    long int len = 0;
    int nb_cols = 0;
    char **map;

    my_help(nargs, args);
    while (++i < nargs) {
        if (args[i][0] == '-')
            i = apply_parameter(i, args, params);
        else
            params->name = args[i];
    }
    params->editor = params->editor | params->nb_lines;
    params->menu = params->menu | !(params->practice | params->editor);
    map = load_map(params->name, &len, &nb_cols);
    if (map == NULL)
        return (84);
    return (my_init(map, params, nb_cols, len));
}
