/*
** EPITECH PROJECT, 2017
** csfml
** File description:
** Creation of a generic button
*/

#include <string.h>
#include <stdlib.h>

#include "lcsfml.h"

lsfButton_t *lsfButton_create(const char *name, lsfSprite_t *sprite, sfVector2f pos,
			    int (*fction)(void *data, lsfButton_t *this))
{
	lsfButton_t *button;
	sfVector2u size;

	button = calloc(1, sizeof(lsfButton_t));
	if (button == NULL)
		return (NULL);
	button->name = strdup(name);
	if (button->name == NULL)
		return (NULL);
	button->fction = fction;
	button->pos = pos;
	button->sprite = sprite;
	size = sfTexture_getSize(sprite->texture);
	button->size = lsfVector2f(size.x, size.y);
	sfSprite_setPosition(sprite->sprite, button->pos);
	return (button);
}

int lsfButton_isPressed(lsfButton_t *button, sfVector2i pos)
{
	sfIntRect rect;
	sfVector2f scale = sfSprite_getScale(button->sprite->sprite);

	lsfRect_init(&rect, button->pos, button->size.x * scale.x, button->size.y * scale.y);
	if (lsfInRect(&rect, pos))
		return (1);
	return (0);
}

int lsfButton_push(lsfButton_t *button, sfVector2i pos, void *data)
{
	if (lsfButton_isPressed(button, pos)) {
		if (button->fction != NULL)
			return (button->fction(data, button));
	}
	return (-1);
}
