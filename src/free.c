/*
** free.c for my_csfml in /home/leandre/C_graphical_prog/tekadventure
**
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
**
** Started on  Wed Apr  5 14:48:58 2017 Léandre Blanchard
** Last update Mon Nov 13 21:53:54 2017 Léandre Blanchard
*/

#include "lcsfml.h"

/*
** When you are loading 5 sprites but with 1 image, such as
** different movement of a player, but cut into pieces,
** so you just loaded 1 texture for the wholes sprites
** which you cut into pieces after, well this fonction
** only frees the texture, and then all the sprites
** replace the freed pointers by NULL
*/
void lsfSprite_destroys_only(lsfSprite_t **sprites)
{
	sfTexture_destroy(sprites[0]->texture);
	for (int i = 0; sprites[i]; ++i) {
		if (sprites[i]->sprite != NULL)
			sfSprite_destroy(sprites[i]->sprite);
		free(sprites[i]);
	}
	free(sprites);
}

/*
** Entirely free a lsfSprite_t ** using a call to lsfSprite_destroy
** and replace the ptr freed, by NULL
*/
void lsfSprite_destroys(lsfSprite_t **sprites)
{
	for (int i = 0; sprites[i]; ++i)
		lsfSprite_destroy(sprites[i]);
	free(sprites);
}

/*
** Free a single lsfSprite_t, then replace it by NULL
*/
void lsfSprite_destroy(lsfSprite_t *sprite)
{
	sfSprite_destroy(sprite->sprite);
	sfTexture_destroy(sprite->texture);
	free(sprite->name);
	free(sprite);
}
/*
** Using a lot of calls to above fonctions,
** frees the whole lsfWindow_t structure
*/
void lsfWindow_destroy(lsfWindow_t *window)
{
	sfRenderWindow_destroy(window->window);
	free(window->pixels);
	if (window->font)
		sfFont_destroy(window->font);
	if (window->frame != NULL) {
		sfTexture_destroy(window->frame->texture);
		sfSprite_destroy(window->frame->sprite);
	}
	free(window->frame);
	free(window);
}
