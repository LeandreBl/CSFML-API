/*
** lsfSprite_create.c for lsfSprite_create in /home/leandre/Rushs/scroller
**
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
**
** Started on  Sun Apr  2 12:20:16 2017 Léandre Blanchard
** Last update Mon Nov 13 21:04:08 2017 Léandre Blanchard
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "lcsfml.h"

#include "lbl-libc.h"
#include "defines.h"
#include "colors.h"

/*
** Create a sprite from <pathname> with the texture at <rect>
** Return NULL on Error
*/
lsfSprite_t *lsfSprite_create_rect(const char *pathname, const sfIntRect area)
{
	lsfSprite_t *sprite;

	printf("[%sInfo%s] Opening %s%s%s\n", YELLOW, RESET, CYAN, pathname,
	       RESET);
	sprite = calloc(1, sizeof(lsfSprite_t));
	if (sprite == NULL)
		return (NULL);
	if (area.top == -1 && area.left == -1 && area.width == -1
	    && area.height == -1)
		sprite->texture = sfTexture_createFromFile(pathname, NULL);
	else
		sprite->texture = sfTexture_createFromFile(pathname, &area);
	sprite->sprite = sfSprite_create();
	if (sprite->texture == NULL || sprite->sprite == NULL) {
		sfTexture_destroy(sprite->texture);
		sfree(&sprite);
		return (NULL);
	}
	sfSprite_setTexture(sprite->sprite, sprite->texture, sfTrue);
	sprite->name = strdup(pathname);
	while (nb_of(sprite->name, '/') != 0)
		shift_left(sprite->name, 1);
	return (sprite);
}

/*
** add the lsfSprite_t "sprite" on the lsfWindow_t "window" at the pos.x, pos.y
** will need a call to lsfWindow_refresh(window) to display it
*/
void lsfPut_sprite(lsfWindow_t *window, lsfSprite_t *sprite, sfVector2f pos)
{
	if (sprite == NULL || sprite->sprite == NULL
	    || sprite->texture == NULL) {
		dprintf(2, "[%sWarning%s] PutSprite : NULL sprite\n", GREEN,
			RESET);
		return;
	}
	sfSprite_setPosition(sprite->sprite, pos);
	sfSprite_setScale(sprite->sprite, lsfVector2f(1, 1));
	sfRenderWindow_drawSprite(window->window, sprite->sprite, NULL);
}
/*
** same as above, but can be resized, for example, resize = { 2, 2 }
** will display the sprite as 2 as large as normal
** does not have any conflict with fonction above
*/
void lsfPut_sprite_resize(lsfWindow_t *window, lsfSprite_t *sprite, sfVector2f pos,
		       sfVector2f resize)
{
	if (sprite == NULL) {
		dprintf(2, "[%sWarning%s] PutSprite : NULL sprite\n", GREEN,
			RESET);
		return;
	}
	sfSprite_setScale(sprite->sprite, resize);
	sfSprite_setPosition(sprite->sprite, pos);
	sfRenderWindow_drawSprite(window->window, sprite->sprite, NULL);
}
/*
** primary lsfSprite_t fonction, create a lsfSprite_t from a file
** getting texture in lsfSprite_t->texture and sprite in lsfSprite_t->sprite
** return NULL on ERROR, and lsfSprite_t malloced on SUCCESS
*/
lsfSprite_t *lsfSprite_create(const char *pathname)
{
	return (lsfSprite_create_rect(pathname, lsfIntRect(-1, -1, -1, -1)));
}
/*
** create an array of lsfSprite_t, ended by a NULL ptr
** then a call to cerate_sprite must be usefull to fill it
*/
lsfSprite_t **lsfSprites_create(int nb)
{
	lsfSprite_t **sprites;

	sprites = calloc(1, sizeof(lsfSprite_t *) * (nb + 1));
	if (sprites == NULL)
		return (NULL);
	for (int i = 0; i < nb; ++i) {
		sprites[i] = calloc(1, sizeof(lsfSprite_t));
		if (sprites[i] == NULL)
			return (NULL);
	}
	return (sprites);
}
