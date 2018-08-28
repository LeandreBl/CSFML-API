/*
** EPITECH PROJECT, 2017
** csfml
** File description:
** find struct with name
*/

#include <string.h>

#include "lcsfml.h"

lsfButton_t *lsfGet_buttonByName(lsfButton_t **buttons, const char *name)
{
	for (int i = 0; buttons[i]; ++i)
		if (strcmp(buttons[i]->name, name) == 0)
			return (buttons[i]);
	return (NULL);
}

lsfSprite_t *lsfGet_spriteByName(lsfSprite_t **sprites, const char *name)
{
	for (int i = 0; sprites[i]; ++i)
		if (strcmp(sprites[i]->name, name) == 0)
			return (sprites[i]);
	return (NULL);
}
