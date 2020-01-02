/*
** EPITECH PROJECT, 2019
** entitylib
** File description:
** internal_data.h
*/

#ifndef INTERNAL_DATA_H_
#define INTERNAL_DATA_H_

typedef struct internal_data {
    int fullscreen;
    sfTexture *cursor_skin;
    sfTexture *pause_skin;
    sfTexture *background_skin;
    sfTexture *level_completed_skin;
    sfImage *icon;
    sfSprite *heart_sprite;
    sfSprite *game_over;
    sfSprite *pause;
    sfSprite *cursor;
    sfSprite *background;
    sfSprite *background2;
    sfSprite *background3;
    sfSprite *level_completed;
    sfFont *text_font;
    sfText *score_text;
} internal_data_t;

internal_data_t *get_internal_data(void);

#endif /* INTERNAL_DATA_H_ */
