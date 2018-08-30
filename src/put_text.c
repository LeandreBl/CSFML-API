/*
7** lsfPut_text.c for  in /home/leandre/Rushs/scroller/lib/CSFML
**
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
**
** Started on  Fri Mar 31 14:08:05 2017 Léandre Blanchard
** Last update Sun Jan  7 09:34:53 2018 Léandre Blanchard
*/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdarg.h>

#include "lcsfml.h"

#include "colors.h"

static int draw_on(lsfWindow_t *window, sfVector2f pos, sfColor color, const char *str)
{
	sfText *text;

	text = sfText_create();
	if (window->font == NULL || text == NULL)
		return (-1);
	sfText_setString(text, str);
	sfText_setFont(text, window->font);
	sfText_setColor(text, color);
	sfText_setCharacterSize(text, 24);
	sfText_setPosition(text, pos);
	sfRenderWindow_drawText(window->window, text, NULL);
	sfText_destroy(text);
	return (0);
}

int lsfPut_text(lsfWindow_t *window, const char *format, sfVector2f pos, sfColor color, ...)
{
	char *s;
	va_list va;

	if (window->font == NULL) {
		dprintf(2, WHITE "[LCSFML]" RESET
			" [%sWarning%s] PutWord : font not set\n",
			GREEN, RESET);
		return (-1);
	}
	va_start(va, color);
	if (vasprintf(&s, format, va) == -1)
		return (-1);
	va_end(va);
	if (draw_on(window, pos, color, s) == -1)
		return (-1);
	free(s);
	return (0);
}
