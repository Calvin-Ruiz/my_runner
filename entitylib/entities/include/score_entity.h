/*
** EPITECH PROJECT, 2019
** entitylib
** File description:
** score_entity.h
*/

#ifndef SCORE_ENTITY_H_
#define SCORE_ENTITY_H_

void score_entity_update(entity_t *self, float delta_time);
entity_t *create_score_entity(sfTexture *t, uint_t *size, float fdelay, int hp);

#endif /* SCORE_ENTITY_H_ */
