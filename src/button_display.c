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
	sfFloatRect frect;
	sfVector2f pos;

	lsfPut_button(window, button, rpos);
	sfText_setFont(button->name, window->font);
	sfText_setColor(button->name, color);
	sfText_setCharacterSize(button->name, 24);
	frect = sfText_getLocalBounds(button->name);
	pos.x = button->pos.x + (button->size.x - frect.width) / 2.0 - frect.left;
	pos.y = button->pos.y + (button->size.y - frect.height) / 2.0 - frect.top;
	sfText_setPosition(button->name, pos);
	sfRenderWindow_drawText(window->window, button->name, NULL);
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
