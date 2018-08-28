/*
** EPITECH PROJECT, 2017
** csfml
** File description:
** button display functions
*/

#include <string.h>

#include "lcsfml.h"
#include "defines.h"
#include "lbl-libc.h"

void lsfPut_button(lsfWindow_t *window, lsfButton_t *button, sfVector2f pos)
{
	lsfWindow_mouse(window);
	button->pos = pos;
	if (lsfButton_isPressed(button, window->mouse)) {
		sfSprite_setColor(button->sprite->sprite,
				  sfColor_fromRGB(100, 100, 100));
		lsfPut_sprite(window, button->sprite, button->pos);
		sfSprite_setColor(button->sprite->sprite, sfWhite);
	}
	else
		lsfPut_sprite(window, button->sprite, button->pos);
}

void lsfPut_button_name(lsfWindow_t *window, lsfButton_t *button, sfVector2f rpos,
			sfColor color)
{
	sfVector2f pos;
	sfVector2f size;

	button->pos = rpos;
	size.x = sstrlen(button->name) * 12;
	size.y = (nb_of(button->name, '\n') + 1) * 24;
	pos.x = button->pos.x + (button->size.x - size.x) / 2;
	pos.y = button->pos.y + (button->size.y - size.y) / 2;
	lsfPut_button(window, button, rpos);
	lsfPut_text(window, button->name, pos, color);
}

void lsfbuttons_draw_name(lsfWindow_t *window, lsfButton_t **buttons,
			    sfColor color)
{
	for (int i = 0; buttons[i]; ++i)
		lsfPut_button_name(window, buttons[i], buttons[i]->pos, color);
}

void lsfbuttons_draw(lsfWindow_t *window, lsfButton_t **buttons)
{
	for (int i = 0; buttons[i]; ++i)
		lsfPut_button(window, buttons[i], buttons[i]->pos);
}
