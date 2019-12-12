/*
** EPITECH PROJECT, 2019
** entitylib
** File description:
** entity_types.h
*/

#ifndef ENTITY_TYPES_H_
#define ENTITY_TYPES_H_

entity_t *create_surface(sfTexture *t, uint_t *size, float fdelay,
    void (*custom)(entity_t *self, void *args));
void bonus_entity_update(entity_t *self, float delta_time);
entity_t *create_bonus_entity(sfTexture *t, uint_t *size, float fdelay, int hp);
void score_entity_update(entity_t *self, float delta_time);
entity_t *create_score_entity(sfTexture *t, uint_t *size, float fdelay, int hp);


#endif /* ENTITY_TYPES_H_ */
