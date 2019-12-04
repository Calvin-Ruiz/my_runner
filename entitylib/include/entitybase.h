/*
** EPITECH PROJECT, 2019
** entitylib
** File description:
** entitybase.h
*/

#ifndef ENTITYBASE_H_
#define ENTITYBASE_H_

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <unistd.h>

typedef unsigned char uchar_t;
typedef unsigned short int ushort_t;
typedef unsigned int uint_t;

typedef struct pos {
    sfVector2f v1;
    sfVector2f v2;
} pos_t;

typedef struct entity {
    sfSprite **sprite;
    int health;
    float timer;
    float frame_delay;
    uchar_t frame_dec;
    uchar_t frame;
    pos_t pos;
    sfVector2f vel;
    uint_t *size;
    void (*update)(struct entity *self, float delta_time);
    void (*custom)(struct entity *self, void *args);
} entity_t;

typedef struct entitylist {
    ushort_t len;
    sfClock *clock;
    sfInt64 last;
    entity_t **list;
} entitylist_t;

typedef struct {
    sfSprite **sprite;
    int health;
    float timer;
    float frame_delay;
    uchar_t frame_dec;
    uchar_t frame;
    pos_t pos;
    sfVector2f vel;
    uint_t *size;
} player_t;

#endif /* ENTITYBASE_H_ */
