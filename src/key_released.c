/*
** EPITECH PROJECT, 2018
** csfml
** File description:
** key released
*/

#include "lcsfml.h"

/*
** Return 1 if the sfKey "key" has been released
*/
int key_released(int key)
{
	if (sfKeyboard_isKeyPressed(key)) {
		while (sfKeyboard_isKeyPressed(key))
			;
		return (1);
	}
	return (0);
}
