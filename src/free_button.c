/*
** EPITECH PROJECT, 2017
** csfml
** File description:
** destroy button
*/

#include "lcsfml.h"

void sfButton_destroys(lsfButton_t **buttons)
{
	for (int i = 0; buttons[i]; ++i)
		sfButton_destroy(buttons[i]);
	free(buttons);
}

void sfButton_destroy(lsfButton_t *button)
{
	free(button->name);
	free(button);
}
