/*
** EPITECH PROJECT, 2019
** entitylib
** File description:
** basic_entity.h
*/

#ifndef BASIC_ENTITY_H_
#define BASIC_ENTITY_H_

void basic_entity_update(entity_t *self, float delta_time);
entity_t *create_base_entity(sfTexture *t, uint_t *size, float fdelay, int hp);
void killed_basic_entity_update(entity_t *self, float delta_time);
void kill_base_entity(entity_t *self, float vel_y);

#endif /* BASIC_ENTITY_H_ */
