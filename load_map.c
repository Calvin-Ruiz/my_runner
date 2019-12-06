/*
** EPITECH PROJECT, 2019
** MUL_my_runner
** File description:
** load_map.c
*/
#include "include/my_read.h"

char **load_map(const char *filename, long int *len, int *nb_cols)
{
    if (filename == NULL)
        return (NULL);
    int fd = open(filename, O_RDONLY);
    if (fd == -1)
        return (NULL);
    char *map = my_read(fd, len);
    if (map == NULL)
        return (NULL);
    *nb_cols = *len / *(map++);
    char **map_2d = malloc(sizeof(void *) * (*nb_cols));
    int i = -1;
    while (++i < *nb_cols) {
        map_2d[i] = map;
        map += *nb_cols;
    }
    return (map_2d);
}
