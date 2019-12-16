/*
** EPITECH PROJECT, 2019
** entitylib
** File description:
** entity.h
*/

#ifndef ENTITY_H_
#define ENTITY_H_

#include "entitybase.h"

void no_update(entity_t *ptr);
void no_custom(entity_t *ptr, entity_t *ptr2);
entity_t *new_instance(entity_t *self, pos_t pos, sfVector2f vel, uchar_t rw);
void entity_blit(entity_t *self, sfRenderWindow *window);
void create_sprite(sfSprite **sprite, sfTexture *texture, uint_t *size);
void free_entity(entity_t *entity);

#endif /* ENTITY_H_ */
