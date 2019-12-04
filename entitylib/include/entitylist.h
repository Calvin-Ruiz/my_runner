/*
** EPITECH PROJECT, 2019
** entitylib
** File description:
** entitylist.h
*/

#ifndef ENTITYLIST_H_
#define ENTITYLIST_H_

void entitylist_blits(entitylist_t *self, sfRenderWindow *window);
void entitylist_updates(entitylist_t *self);
void entitylist_append(entitylist_t *self, entity_t *entity);
entitylist_t *create_entitylist(ushort_t len);
void destroy_entitylist(entitylist_t *entitylist);

#endif /* ENTITYLIST_H_ */
