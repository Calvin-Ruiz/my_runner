/*
** EPITECH PROJECT, 2019
** entitylib
** File description:
** entity.h
*/

#ifndef ENTITY_H_
#define ENTITY_H_

#include "entitybase.h"

void no_custom(entity_t *self, void *args);
entity_t *new_instance(entity_t *self, sfVector2f *pos, float *vel, uchar_t rw);
void entity_blit(entity_t *self, sfRenderWindow *window);
void create_sprite(sfSprite **sprite, sfTexture *texture, uint_t *size);
void free_entity(entity_t *entity);

#endif /* ENTITY_H_ */
