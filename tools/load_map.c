/*
** EPITECH PROJECT, 2019
** MUL_my_runner
** File description:
** load_map.c
*/
#include "include/my_read.h"
#include <entitybase.h>
#include <data_storage.h>
#include <string.h>

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
    fd = open(full_path, O_RDONLY);
    free(full_path);
    return (fd);
}

static char **create_map(long int *len, int *nb_cols, char nb_lines_param)
{
    if (nb_lines_param == 0)
        return (NULL);
    char *map = malloc(nb_lines_param + 1);
    if (map == NULL)
        return (NULL);
    char **map_2d = malloc(sizeof(char *));
    memset(map, 0, nb_lines_param + 1);
    *map = nb_lines_param;
    *map_2d = map + 1;
    *nb_cols = 1;
    *len = nb_lines_param + 1;
    get_data_storage()->col = 0.f;
    return (map_2d);
}

static char *my_entry_filename(void)
{
    char *buffer = malloc(128);
    int size = 0;

    write(1, "Entry your level name (e.g. map.lvl) : ", 39);
    size = read(0, buffer, 128);
    if (size < 5) {
        write(1, "Invalid entry.\n", 15);
        free(buffer);
        return (NULL);
    } else if (size == 128) {
        write(1, "Too long name.\n", 15);
        free(buffer);
        return (NULL);
    }
    buffer[size] = '\0';
    return (buffer);
}

char **load_map(char *filename, long int *len, int *nb_cols,
    char nb_lines_param)
{
    if (filename == NULL)
        filename = my_entry_filename();
    int fd = my_opener(filename);
    char **map_2d;
    if (fd == -1) {
        map_2d = create_map(len, nb_cols, nb_lines_param);
        return (map_2d);
    }
    char *map = my_read(fd, len);
    if (map == NULL)
        return (NULL);
    const char nb_lines = *(map++);
    *nb_cols = *len / nb_lines;
    map_2d = malloc(sizeof(void *) * (*nb_cols));
    int i = -1;
    while (++i < *nb_cols) {
        map_2d[i] = map;
        map += nb_lines;
    }
    return (map_2d);
}
