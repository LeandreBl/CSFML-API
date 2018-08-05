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

int button_poll_event(window_t *window, sfEvent *event, sfbutton_t **buttons,
		      void *data)
{
	sfVector2i coord;

	(void)window;
	coord = xy_vectori(event->mouseButton.x, event->mouseButton.y);
	for (int i = 0; buttons[i] != NULL; ++i)
		sfbutton_exec(buttons[i], coord, data);
	return (0);
}

void add_evt(evtptr_t *index, int type, evt_t fction)
{
	index->type = type;
	index->fction = fction;
}

int ptr_pollevent(window_t *window, evtptr_t tab[], int size, void *data)
{
	sfEvent event;

	while (sfRenderWindow_pollEvent(window->window, &event)) {
		for (int i = 0; i < size; ++i) {
			if (event.type == tab[i].type) {
				if (tab[i].fction == NULL)
					dprintf(2,
						"[%sWarning%s] pollEvent "
						"function pointer n°%d is "
						"NULL\n",
						GREEN, RESET, i);
				else if (tab[i].fction(window, &event, data)
					 == -1)
					return (-1);
			}
		}
	}
	return (0);
}
