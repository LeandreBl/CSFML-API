/*
** csfml.h for csfml_h_lib in /home/leandre/Rushs/scroller/lib/CSFML
**
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
**
** Started on  Fri Mar 31 13:58:23 2017 Léandre Blanchard
** Last update Thu Jan 11 08:36:04 2018 Léandre Blanchard
*/

#ifndef LCSFML_H_
# define LCSFML_H_

#ifdef __cplusplus
extern "C" {
#endif
#ifdef __horriblethingwithemacs
}
#endif

# include <SFML/Audio.h>
# include <SFML/Network.h>
# include <SFML/Graphics.h>
# include <SFML/System.h>
# include <SFML/Window.h>

# include <stdlib.h>
# include <math.h>
# include <unistd.h>

# define KP(key) (sfKeyboard_isKeyPressed(key))
# define MP (sfMouse_isButtonPressed(sfMouseLeft))
# define ORIGIN (lsfVector2f(0, 0))

/*
** Simple sprite structure, saving the texture and the sprite,
** can be easely used with lsfPut_sprite, and create via a call
** of lsfSprite_create(<pathname>)
*/
typedef struct sprite_s
{
	char *name;
	sfSprite *sprite;
	sfTexture *texture;
} lsfSprite_t;

/*
** A window structure, containing it's size,
** the position of the mouse using lsfWindow_mouse
** a char * containing the name of the font for
** lsfPut_text fcontions
** an array of pixels, of the size of the window
** an array of sfMusics *ptr
** a texture linked to the array of pixels, same for the sprite
*/
typedef struct window_s
{
	int width;
	int height;
	sfVector2i mouse;
	sfRenderWindow *window;
	sfUint8 *pixels;
	char *font;
	sfMusic **musics;
	struct sprite_s *frame;
} lsfWindow_t;

typedef int (* lsfEvt_t)(struct window_s *window,
    sfEvent *event, void *data);

typedef struct evtptr_s
{
	sfEventType type;
	lsfEvt_t fction;
} lsfEvtPtr_t;

typedef struct lsfbutton_s
{
  struct sprite_s *sprite;
  char *name;
  sfVector2f pos;
  sfVector2f size;
  int (*fction)(void *data, struct lsfbutton_s *this);
} lsfButton_t;

int lsfScript(const char *pathname, const char *script,
		lsfSprite_t ***ptr);

sfIntRect lsfIntRect(int x, int y, int width, int height);

void lsfDrawLine(lsfWindow_t *window, sfVector2f from,
		  sfVector2f to, sfColor color);

void lsfSprite_destroy(lsfSprite_t *sprite);

void lsfSprites_destroy_only(lsfSprite_t **sprites);

sfUint8 *pixels_buffer(int width, int height);

void sfThread_kill(sfThread *thread);

void lsfWidnow_destroy(lsfWindow_t *window);

void lsfSprites_destroy(lsfSprite_t **sprites);

lsfSprite_t **lsfSprites_create(int nb);

void lsfRect_init(sfIntRect *rect, sfVector2f pos, 
		int width, int height);

int lsfInRect(const sfIntRect *rect, sfVector2i pos);

int lsfIsInRect(lsfWindow_t *window, const sfIntRect *rect);

void lsfWindow_clear(lsfWindow_t *window);

int lsfKeyReleased(int key);

void lsfWindow_update(lsfWindow_t *window);

void lsfWindow_refresh(lsfWindow_t *window);

void lsfPut_sprite(lsfWindow_t *window,
		lsfSprite_t *sprite, sfVector2f pos);

void lsfPut_sprite_resize(lsfWindow_t *window, lsfSprite_t *sprite,
		       sfVector2f pos, sfVector2f resize);

void lsfWindow_close(lsfWindow_t *window);

sfVector2i lsfVector2i(int x, int y);

sfVector2f lsfVector2f(float x, float y);

sfVector3f lsfVector3f(float x, float y, float z);

sfVector2i lsfWindow_mouse(lsfWindow_t *window);

void lsfPut_square(sfVector2i pos, sfColor color,
		lsfWindow_t *window, int size);

void lsfPut_circle(lsfWindow_t *window, sfVector2f pos,
		 int size, sfColor color);

void lsfPut_png_resize(lsfWindow_t *window, sfVector2f pos,
		    const char *name, sfVector2f resize);

void lsfPut_png(lsfWindow_t *window, sfVector2f pos, const char *name);

int lsfPut_pixel(lsfWindow_t *window, int x, int y, sfColor color);

void lsfWindow_set(lsfWindow_t *window, sfColor color);

void lsfWindow_setWhite(lsfWindow_t *window);

int lsfPut_text(lsfWindow_t *window, const char *format, sfVector2f pos, sfColor color, ...);

lsfWindow_t *lsfWindow_create(int height, float dim, char *name, int bar);

lsfSprite_t *lsfSprite_create(const char *pathname);
lsfSprite_t *lsfSprite_create_rect(const char *pathname,
			     const sfIntRect area);

double lsfDistance(sfVector2f a, sfVector2f b);

lsfButton_t *lsfButton_create(const char *name, lsfSprite_t *sprite,
			    sfVector2f pos,
			    int (*fction)(void *data, lsfButton_t *this));
int lsfButton_isPressed(lsfButton_t *button, sfVector2i pos);

void lsfPut_button(lsfWindow_t *window, lsfButton_t *button, sfVector2f pos);

void lsfPut_button_name(lsfWindow_t *window, lsfButton_t *button,
			sfVector2f pos, sfColor color);
int lsfButton_push(lsfButton_t *button, sfVector2i pos, void *data);

void sfButton_destroy(lsfButton_t *button);

void sfButtons_destroy(lsfButton_t **buttons);

int lsfPollEvent(lsfWindow_t *window, lsfEvtPtr_t tab[],
		  int size, void *data);

void lsfEvt_set(lsfEvtPtr_t *index, int type, lsfEvt_t fction_ptr);

int lsfButtonPollEvent(lsfWindow_t *window, sfEvent *event,
		      lsfButton_t **buttons, void *data);

void lsfPut_buttons_name(lsfWindow_t *window, lsfButton_t **buttons,
			    sfColor color);

void lsfPut_buttons(lsfWindow_t *window, lsfButton_t **buttons);

lsfButton_t *lsfGet_buttonByName(lsfButton_t **buttons, const char *name);

lsfSprite_t *lsfGet_spriteByName(lsfSprite_t **sprites, const char *name);

#ifdef __cplusplus
}
#endif

#endif /* !LCSFML_H_ */
