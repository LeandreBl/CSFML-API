/*
** EPITECH PROJECT, 2017
** csfml
** File description:
** lsfDistance
*/

#include "lcsfml.h"

static double _cube_(double a)
{
	return (a * a);
}

/* Calculate the lsfDistance between 2 points */
double lsfDistance(sfVector2f a, sfVector2f b)
{
	return (sqrt(_cube_(a.x - b.x) + _cube_(a.y - b.y)));
}
