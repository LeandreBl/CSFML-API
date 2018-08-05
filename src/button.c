/*
** EPITECH PROJECT, 2017
** csfml
** File description:
** Creation of a generic button
*/

#include <string.h>
#include <stdlib.h>

#include "lcsfml.h"

sfbutton_t *sfbutton_create(const char *name, sprite_t *sprite, sfVector2f pos,
			    int (*fction)(void *data, sfbutton_t *this))
{
	sfbutton_t *button;
	sfVector2u size;

	button = calloc(1, sizeof(sfbutton_t));
	if (button == NULL)
		return (NULL);
	button->name = strdup(name);
	button->fction = fction;
	button->pos = pos;
	button->sprite = sprite;
	size = sfTexture_getSize(sprite->texture);
	button->size = xy_vectorf(size.x, size.y);
	sfSprite_setPosition(sprite->sprite, button->pos);
	return (button);
}

int sfbutton_ispressed(sfbutton_t *button, sfVector2i pos)
{
	sfIntRect rect;

	if (button == NULL)
		return (0);
	fill_rect(button->pos, button->size.x, button->size.y, &rect);
	if (in_rect(pos, &rect))
		return (1);
	return (0);
}

int sfbutton_exec(sfbutton_t *button, sfVector2i pos, void *data)
{
	if (sfbutton_ispressed(button, pos)) {
		if (button->fction != NULL)
			return (button->fction(data, button));
	}
	return (-1);
}
