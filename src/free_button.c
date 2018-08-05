/*
** EPITECH PROJECT, 2017
** csfml
** File description:
** destroy button
*/

#include "lcsfml.h"

void free_sfbuttons(sfbutton_t **buttons)
{
	for (int i = 0; buttons[i]; ++i)
		free_sfbutton(buttons[i]);
	free(buttons);
}

void free_sfbutton(sfbutton_t *button)
{
	free(button->name);
	free(button);
}
