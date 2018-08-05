/*
** EPITECH PROJECT, 2018
** lcsfml
** File description:
** draw line
*/

#include "lcsfml.h"

/*
** Swap the two vector if from.x is lower than to.x
*/
static void swaper(sfVector2f *from, sfVector2f *to)
{
	sfVector2f swp;

	swp = *from;
	*from = *to;
	*to = swp;
}

/*
** Draw a line from "from" to "to" with sfColor "color"
*/
void draw_line(window_t *window, sfVector2f from, sfVector2f to,
		  sfColor color)
{
	float a;
	float b;

	if (from.y > to.y)
		swaper(&from, &to);
	while (from.x == to.x && from.y <= to.y)
		put_pixel(window, (int)from.x, (int)from.y++, color);
	if (from.x > to.x)
		swaper(&from, &to);
	while (from.y == to.y && from.x <= to.x)
		put_pixel(window, (int)from.x++, (int)from.y, color);
	a = (to.y - from.y) / (to.x - from.x);
	b = from.y - (a * from.x);
	while ((a <= 0.5 || a >= -0.5) && from.x <= to.x) {
		from.y = a * from.x + b;
		put_pixel(window, (int)from.x, (int)from.y, color);
		from.x += 0.2;
	}
	while ((a >= 0.5 || a <= -0.5) && from.y <= to.y) {
		from.x = a * from.x + b;
		put_pixel(window, (int)from.x, (int)from.y, color);
		from.y += 0.2;
	}
}
