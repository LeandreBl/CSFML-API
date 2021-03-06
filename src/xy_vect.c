/*
** xy_vect.c for xy_vect in /home/leandre/Rushs/scroller/lib/CSFML
**
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
**
** Started on  Fri Mar 31 14:21:49 2017 Léandre Blanchard
** Last update Thu Nov 16 19:58:34 2017 Léandre Blanchard
*/

#include "lcsfml.h"

/*
** Does functions all return a sfVector with it's following instructions
** x, y and z
*/
sfVector2f lsfVector2f(float x, float y)
{
	sfVector2f xy;

	xy.x = x;
	xy.y = y;
	return (xy);
}

sfVector2i lsfVector2i(int x, int y)
{
	sfVector2i xy;

	xy.x = x;
	xy.y = y;
	return (xy);
}

sfVector3f lsfVector3f(float x, float y, float z)
{
	sfVector3f xyz;

	xyz.x = x;
	xyz.y = y;
	xyz.z = z;
	return (xyz);
}
