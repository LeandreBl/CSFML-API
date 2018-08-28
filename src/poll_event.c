/*
** EPITECH PROJECT, 2017
** csfml
** File description:
** auto poll event
*/

#include <stdio.h>

#include "lcsfml.h"

#include "defines.h"
#include "colors.h"

int lsfButtonPollEvent(lsfWindow_t *window, sfEvent *event, lsfButton_t **buttons,
		      void *data)
{
	sfVector2i coord;

	(void)window;
	coord = lsfVector2i(event->mouseButton.x, event->mouseButton.y);
	for (int i = 0; buttons[i] != NULL; ++i)
		lsfButton_push(buttons[i], coord, data);
	return (0);
}

void lsfEvt_set(lsfEvtPtr_t *index, int type, lsfEvt_t fction)
{
	index->type = type;
	index->fction = fction;
}

int lsfPollEvent(lsfWindow_t *window, lsfEvtPtr_t tab[], int size, void *data)
{
	sfEvent event;

	while (sfRenderWindow_pollEvent(window->window, &event)) {
		for (int i = 0; i < size; ++i) {
			if (event.type == tab[i].type) {
				if (tab[i].fction == NULL)
					dprintf(2, "[%sLCSFML%s]"
						"[%sWarning%s] pollEvent "
						"function pointer n°%d is "
						"NULL\n", WHITE, RESET,
						GREEN, RESET, i);
				else if (tab[i].fction(window, &event, data)
					 == -1)
					return (-1);
			}
		}
	}
	return (0);
}
