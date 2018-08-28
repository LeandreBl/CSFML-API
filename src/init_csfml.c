/*
** init_csfml.c for init_csfml_structs in /home/leandre/Rushs/scroller/lib/CSFML
**
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
**
** Started on  Fri Mar 31 14:24:11 2017 Léandre Blanchard
** Last update Mon Nov 13 22:27:43 2017 Léandre Blanchard
*/

#include <stdio.h>
#include <stdlib.h>

#include "lcsfml.h"

#include "colors.h"

/*
** Create the sfRenderWindow object, with it's size and name
** return NULL on error
*/
sfRenderWindow *create_window(char *name, int width, int height, int bar)
{
	sfRenderWindow *window;
	sfVideoMode mode;

	if (bar == -1)
		bar = sfClose | sfResize | sfTitlebar;
	mode.width = width;
	mode.height = height;
	mode.bitsPerPixel = 32;
	window = sfRenderWindow_create(mode, name, bar, NULL);
	return (window);
}
/*
** Create a sfUint8 array of pixels, of size width * heiht
** multiplied by 4, for R G B A.
** return NULL on error
*/
sfUint8 *pixels_buffer(int width, int height)
{
	int *pixels;

	pixels = malloc(width * height * sizeof(int));
	for (int i = 0; i < width * height; ++i)
		pixels[i] = 0;
	return ((sfUint8 *)pixels);
}
/*
** Create a lsfWindow_t object, all malloc and initialized with NULL
** for a Window names "CSFML" of size 1280 * 720
** you'll have to call inilsfWindow_t(720, 16 / 9, "CSFML)
** dim is the ratio of the screen, such as 16/9, 4/3 ...
** bar can be set so the window has no button on top of it, so you can create
** your owns ! by entering 0, other possibility are sfClose | sfResize |
*sfTitlebar
** return NULL on error
*/
lsfWindow_t *lsfWindow_create(int height, float dim, char *name, int bar)
{
	lsfWindow_t *window;

	window = malloc(sizeof(lsfWindow_t));
	if (window == NULL)
		return (NULL);
	window->height = height;
	window->width = window->height * dim;
	window->pixels = pixels_buffer(window->width, window->height);
	window->window =
		create_window(name, window->width, window->height, bar);
	window->frame = calloc(1, sizeof(lsfSprite_t));
	if (!window->pixels || !window->window || !window->pixels) {
		dprintf(2, "[%sError%s] : Failed to create %s CSFML window\n",
			BOLDRED, RESET, name);
		return (NULL);
	}
	window->frame->sprite = sfSprite_create();
	window->frame->texture =
		sfTexture_create(window->width, window->height);
	sfSprite_setTexture(window->frame->sprite, window->frame->texture,
			    sfTrue);
	window->font = NULL;
	return (window);
}
