/*
** EPITECH PROJECT, 2019
** entitylib
** File description:
** player.h
*/

#ifndef PLAYER_H_
#define PLAYER_H_

entity_t *create_player_entity(sfTexture *t, uint_t *size, float fdelay,
    int hp);
player_t *create_player(int nb_cols);

#endif /* PLAYER_H_ */
