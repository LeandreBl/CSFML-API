/*
** EPITECH PROJECT, 2017
** csfml
** File description:
** destroy button
*/

#include "lcsfml.h"

void lsfButton_destroys(lsfButton_t **buttons)
{
	for (int i = 0; buttons[i]; ++i)
		lsfButton_destroy(buttons[i]);
	free(buttons);
}

void lsfButton_destroy(lsfButton_t *button)
{
	sfText_destroy(button->name);
	free(button);
}
