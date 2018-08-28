/*
** quit.c for csfml in /home/leandre/C_graphical_prog/tekadventure
**
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
**
** Started on  Tue Apr  4 22:01:01 2017 Léandre Blanchard
** Last update Sat Jun  3 17:00:14 2017 Léandre Blanchard
*/

#include "lcsfml.h"

/*
** this fonction need to be added in a display loop
** this fonction does not return, but close the window
** in lsfWindow_t->window, is the user clic on the 'x' o the window
** or press Escape (echap in french)
*/
void lsfWindow_close(lsfWindow_t *win)
{
	sfRenderWindow_close(win->window);
}
