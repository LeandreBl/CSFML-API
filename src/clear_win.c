/*
** clear_win.c for clear_win in /home/leandre/Rushs/scroller/lib/CSFML
**
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
**
** Started on  Fri Mar 31 14:04:57 2017 Léandre Blanchard
** Last update Mon Nov 13 22:27:06 2017 Léandre Blanchard
*/

#include "lcsfml.h"
/*
** clear the lsfWindow_t current's sprites
*/
void lsfWindow_clear(lsfWindow_t *window)
{
	sfRenderWindow_clear(window->window, sfWhite);
}

/* Updates the window from the pixels */
void lsfWindow_update(lsfWindow_t *window)
{
	sfTexture_updateFromPixels(window->frame->texture, window->pixels,
				   window->width, window->height, 0, 0);
	lsfPut_sprite(window, window->frame, ORIGIN);
}

/*
** refresh the window by displaying the sprites,
** and the pixels contained in window->pixels
*/
void lsfWindow_refresh(lsfWindow_t *window)
{
	lsfWindow_update(window);
	sfRenderWindow_display(window->window);
}

/*
** Fill all the pixel of window->pixels with color
*/
void lsfWindow_set(lsfWindow_t *window, sfColor color)
{
	int x;
	int y;

	y = 0;
	while (y < window->height) {
		x = 0;
		while (x < window->width) {
			lsfPut_pixel(window, x, y, color);
			++x;
		}
		y++;
	}
}

/*
** fill all the bytes of the pixel array in lsfWindow_t
** with blank
*/
void lsfWindow_setWhite(lsfWindow_t *window)
{
	int i;
	int *pixels;

	pixels = (int *)window->pixels;
	i = 0;
	while (i != window->height * window->width)
		pixels[i++] = 255;
}
