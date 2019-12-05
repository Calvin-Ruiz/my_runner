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

static void my_init(char **map, param_t *params, int nb_cols, long int len)
{
    
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
    my_init(map, params, nb_cols, len);
    return (0);
}
