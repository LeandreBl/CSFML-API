/*
** lsfPut_square.c for my_lsfPut_square.c in /home/leandre/Rushs/scroller/lib/CSFML
**
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
**
** Started on  Fri Mar 31 13:58:02 2017 Léandre Blanchard
** Last update Sat Jun  3 16:57:01 2017 Léandre Blanchard
*/

#include "lcsfml.h"

/*
** Draw a square on lsfWindow_t "window" at coordinates "pos"
** with color "color", with size "size"
** where "size" is the height/width size,
** if size == 2, it will draw 4 pixels of "color" color
** This function does not return
*/
void lsfPut_square(sfVector2i pos, sfColor color, lsfWindow_t *window, int size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i != size) {
		lsfPut_pixel(window, pos.x + i, pos.y + j, color);
		j++;
		if (j == size) {
			i++;
			j = 0;
		}
	}
}
