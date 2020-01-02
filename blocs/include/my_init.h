/*
** EPITECH PROJECT, 2019
** MUL_my_runner
** File description:
** my_init.h
*/

#ifndef MY_INIT_H_
#define MY_INIT_H_

#include <entitylib.h>
#include <player.h>

void my_jump(entity_t *self, entity_t *target);
void my_kill(entity_t *self, entity_t *target);
void my_gravity_inverter(entity_t *entity, entity_t *target);
void my_ice(entity_t *self, entity_t *target);
void my_stick(entity_t *self, entity_t *target);
void my_cinetic_inverter(entity_t *self, entity_t *target);
void my_water(entity_t *self, entity_t *target);
void my_bubble(entity_t *self, entity_t *target);

void my_switch(entity_t *self);

void my_jump_sphere(entity_t *self, entity_t *target);
void my_overjump_sphere(entity_t *self, entity_t *target);
void my_anti_jump_sphere(entity_t *self, entity_t *target);
void my_gravity_inverter_sphere(entity_t *self, entity_t *target);
void my_cinetic_boost_sphere(entity_t *self, entity_t *target);
void my_cinetic_inverter_sphere(entity_t *self, entity_t *target);
void my_tp_sphere(entity_t *self, entity_t *target);
void my_creation_sphere(entity_t *self, entity_t *target);

void my_normal_gravity_portal(entity_t *self, entity_t *target);
void my_gravity_inverter_portal(entity_t *self, entity_t *target);
void my_switch_gravity_portal(entity_t *self, entity_t *target);
void my_cinetic_boost_portal(entity_t *self, entity_t *target);
void my_cinetic_inverter_portal(entity_t *self, entity_t *target);

#endif /* MY_INIT_H_ */
