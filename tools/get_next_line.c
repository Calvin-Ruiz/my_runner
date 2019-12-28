/*
** EPITECH PROJECT, 2019
** CPE_getnextline
** File description:
** get_next_line.c
*/

#include "include/my_read.h"

char *fast_get_next_line(int fd)
{
    static int fd_old = 0;
    static long int pos = -2;
    static long int len = 0;
    static char *str = NULL;
    if (pos == -2 || fd != fd_old || str == NULL) {
        pos = -1;
        fd_old = fd;
        len = 0;
        str = my_read(fd, &len);
    }
    if (pos >= len && str) {
        free(str);
        str = NULL;
    }
    if (str == NULL)
        return (NULL);
    int pos2 = pos;
    while (++pos < len && str[pos] != '\n');
    str[pos] = '\0';
    return (str + pos2 + 1);
}

char *get_next_line(int fd)
{
    char *str = fast_get_next_line(fd);
    int i = -1;
    int size = 0;
    char *str2;

    if (str == NULL)
        return (NULL);
    while (str[size++] != '\0');
    str2 = malloc(sizeof(size));
    while (++i < size)
        str2[i] = str[i];
    return (str2);
}
