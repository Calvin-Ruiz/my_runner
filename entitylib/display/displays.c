/*
** EPITECH PROJECT, 2019
** entitylib
** File description:
** displays.c
*/
#include <entitybase.h>
#include <data_storage.h>
#include <internal_data.h>

static void my_write_score(char *str1, char *str2, data_storage_t *datas)
{
    int score = datas->score;
    int higher_score = datas->higher_score;

    while (score > 0) {
        str1--[0] = score % 10 + '0';
        score /= 10;
    }
    while (higher_score > 0) {
        str2--[0] = higher_score % 10 + '0';
        higher_score /= 10;
    }
}

void my_game_over(sfRenderWindow *window, internal_data_t *datas,
    data_storage_t *stor)
{
    sfClock *my_clock = sfClock_create();
    sfVector2f pos;

    sfRenderWindow_drawSprite(window, datas->game_over, NULL);
    if (stor->score > stor->higher_score) {
        pos.x = 650;
        pos.y = 500;
        char str[] = "New best score !\nNow  :  00000000\nBefore : 00000000";
        my_write_score(str + 32, str + 50, stor);
        sfText_setString(datas->score_text, str);
        sfText_setPosition(datas->score_text, pos);
        sfRenderWindow_drawText(window, datas->score_text, NULL);
        pos.x = 1200;
        pos.y = 716;
        sfText_setPosition(datas->score_text, pos);
    }
    sfRenderWindow_display(window);
    while (sfClock_getElapsedTime(my_clock).microseconds < 2500000);
    sfClock_destroy(my_clock);
}

int init_heart_and_score(sfTexture *heart, sfTexture *end_texture)
{
    internal_data_t *datas = get_internal_data();
    sfVector2f pos;

    pos.x = 1200;
    pos.y = 716;
    datas->game_over = sfSprite_create();
    datas->heart_sprite = sfSprite_create();
    if (datas->heart_sprite == NULL || datas->game_over == NULL)
        return (84);
    sfSprite_setTexture(datas->game_over, end_texture, sfTrue);
    sfSprite_setTexture(datas->heart_sprite, heart, sfTrue);
    datas->score_text = sfText_create();
    datas->text_font = sfFont_createFromFile("textures/text_font.otf");
    if (datas->score_text == NULL || datas->text_font == NULL)
        return (84);
    sfText_setFont(datas->score_text, datas->text_font);
    sfText_setFillColor(datas->score_text, sfBlack);
    sfText_setPosition(datas->score_text, pos);
    return (0);
}

void display_health_and_score(sfRenderWindow *window, data_storage_t *stor,
    internal_data_t *datas)
{
    sfVector2f pos;
    int health = stor->player->entity->health;
    char str[] = "Your score : 00000000\n Best score : 00000000";

    my_write_score(str + 20, str + 43, stor);
    if (health == 0)
        my_game_over(window, datas, stor);
    pos.x = 4;
    pos.y = 760;
    while (health-- > 0) {
        sfSprite_setPosition(datas->heart_sprite, pos);
        sfRenderWindow_drawSprite(window, datas->heart_sprite, NULL);
        pos.x += 32;
    }
    sfText_setString(datas->score_text, str);
    sfRenderWindow_drawText(window, datas->score_text, NULL);
}

void destroy_heart_and_score(void)
{
    internal_data_t *datas = get_internal_data();

    sfSprite_destroy(datas->game_over);
    sfSprite_destroy(datas->heart_sprite);
    sfFont_destroy(datas->text_font);
    sfText_destroy(datas->score_text);
}
