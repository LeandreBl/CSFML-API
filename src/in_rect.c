/*
** lsfInRect.c for CSFML in /home/leandre/C_graphical_prog/tekadventure
**
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
**
** Started on  Thu Apr 20 09:14:16 2017 Léandre Blanchard
** Last update Thu Nov 16 20:02:22 2017 Léandre Blanchard
*/

#include "lcsfml.h"

/* Fill the given *rect pointer */
void lsfRect_init(sfIntRect *rect, sfVector2f pos, int width, int height)
{
	rect->left = pos.x;
	rect->top = pos.y;
	rect->width = width;
	rect->height = height;
}

/* Create a sfIntRect from it's 4 values */
sfIntRect lsfIntRect(int x, int y, int width, int height)
{
	sfIntRect rect;

	rect.left = x;
	rect.top = y;
	rect.width = width;
	rect.height = height;
	return (rect);
}

/* Return 1 if pos is inside the given rect, else 0 */
int lsfInRect(const sfIntRect *rect, sfVector2i pos)
{
	if (pos.x < rect->left || pos.x > rect->left + rect->width
		|| pos.y < rect->top || pos.y > rect->top + rect->height)
		return (0);
	return (1);
}

/*
** This function refresh the position of the mouse in lsfWindow_t->mouse
** and return 0 if the mouse is located in the rectangle
** of size size.x * size.y who upper-left corner is at (origin.x, origin.y)
*/
int lsfIsInRect(lsfWindow_t *window, const sfIntRect *rect)
{
	lsfWindow_mouse(window);
	return (sfIntRect_contains(rect, window->mouse.x, window->mouse.y));
}
