/*
** my_lsfPut_pixel.c for lsfPut_pixel in /home/leandre/Rushs/scroller/lib/CSFML
**
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
**
** Started on  Fri Mar 31 13:56:13 2017 Léandre Blanchard
** Last update Tue Nov  7 22:22:42 2017 Léandre Blanchard
*/

#include "lcsfml.h"

/*
** Put a pixel in window->pixels array of sfUint8
** at coordinates (x, y) with RGBA color "color"
** return -1 on error
*/
int lsfPut_pixel(lsfWindow_t *window, int x, int y, sfColor color)
{
	int offset;

	if (x < 0 || y < 0)
		return (-1);
	if (x >= window->width || y >= window->height)
		return (-1);
	offset = (window->width * y + x) * 4;
	window->pixels[offset + 0] = color.r;
	window->pixels[offset + 1] = color.g;
	window->pixels[offset + 2] = color.b;
	window->pixels[offset + 3] = color.a;
	return (0);
}
