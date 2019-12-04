/*
** EPITECH PROJECT, 2019
** entitylib
** File description:
** bonus_entity.h
*/

#ifndef BONUS_ENTITY_H_
#define BONUS_ENTITY_H_

void bonus_entity_update(entity_t *self, float delta_time);
entity_t *create_bonus_entity(sfTexture *t, uint_t *size, float fdelay, int hp);

#endif /* BONUS_ENTITY_H_ */
