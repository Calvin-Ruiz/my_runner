/*
** EPITECH PROJECT, 2019
** entitylib
** File description:
** converters.h
*/

#ifndef CONVERTERS_H_
#define CONVERTERS_H_

#include <fcntl.h>

typedef union double_raw {
    double value;
    char raw[sizeof(double)];
} double_to_raw_t;

typedef union float_raw {
    float value;
    char raw[sizeof(float)];
} float_to_raw_t;

typedef union long_raw {
    long int value;
    char raw[sizeof(long int)];
} long_to_raw_t;

typedef union int_raw {
    int value;
    char raw[sizeof(int)];
} int_to_raw_t;

typedef union short_raw {
    short value;
    char raw[sizeof(short)];
} short_to_raw_t;

typedef union pos_raw {
    sfVector2f value;
    char raw[sizeof(sfVector2f)];
} pos_to_raw_t;

typedef union int64_raw {
    sfInt64 value;
    char raw[sizeof(sfInt64)];
} int64_to_raw_t;

typedef union data_storage_raw {
    struct {
        int score;
    } data;
    char raw[4];
} data_storage_to_raw_t;

typedef union entity_raw {
    struct {
        short id_master;
        int health;
        unsigned char frame;
        unsigned char frame_dec;
        long long frame_delay;
        sfVector2f vel;
        pos_t pos;
    } data;
    char raw[8 + sizeof(long long) + sizeof(sfVector2f) + sizeof(pos_t)];
} entity_to_raw_t;

#endif /* CONVERTERS_H_ */
