/*
** EPITECH PROJECT, 2019
** MUL_my_runner
** File description:
** main.c
*/
#include "include/main.h"

int apply_parameter(int i, char **args, param_t *parameters)
{
    switch (args[i][1]) {
    case 'f':
        if (args[i + 1] != NULL)
            parameters->fps = my_getnbr(args[i + 1]);
        return (i + 1);
    case 'p':
        parameters->practice = 1;
        return (i);
    case 'r':
        parameters->menu = 0;
        return (i);
    case 'e':
        parameters->editor = 1;
        return (i + 1);
    case 'n':
        if (++args != NULL)
            parameters->nb_lines = my_getnbr(args[i + 1]);
        return (i + 1);
    }
    return (i);
}

int main(int nargs, char **args)
{
    int i = 0;
    param_t params[1];
    *params = (param_t) {60, '\0' + 1, '\0', '\0', 0, '\0', NULL};
    while (++i < nargs) {
        if (args[i][0] == '-')
            i = apply_parameter(i, args, params);
        else
            params->name = args[i];
    }
    params->editor = params->editor | params->nb_lines;
    params->menu = params->menu | !(params->practice | params->editor);
}
