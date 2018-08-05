/*
** EPITECH PROJECT, 2017
** csfml
** File description:
** find struct with name
*/

#include <string.h>

#include "lcsfml.h"

sfbutton_t *button_by_name(sfbutton_t **buttons, const char *name)
{
	for (int i = 0; buttons[i]; ++i)
		if (strcmp(buttons[i]->name, name) == 0)
			return (buttons[i]);
	return (NULL);
}

sprite_t *sprite_by_name(sprite_t **sprites, const char *name)
{
	for (int i = 0; sprites[i]; ++i)
		if (strcmp(sprites[i]->name, name) == 0)
			return (sprites[i]);
	return (NULL);
}
