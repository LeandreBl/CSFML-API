/*
** EPITECH PROJECT, 2017
** csfml
** File description:
** load script from a file
*/

#define _GNU_SOURCE
#include <string.h>
#include <stdio.h>

#include "lcsfml.h"
#include "defines.h"
#include "lbl-libc.h"
#include "colors.h"

#define CSFML_ERR "[" WHITE "LCSFML" RESET "] "
#define SCRIPT_TAG "name : "
#define LOAD_TAG "load > "

static int reach_script(char **file, const char *script)
{
	char *line;

	if (asprintf(&line, "%s%s", SCRIPT_TAG, script) == -1)
		return (-1);
	for (int i = 0; file[i]; ++i) {
		epur_str(file[i]);
		if (strcmp(file[i], line) == 0) {
			free(line);
			return (i);
		}
	}
	free(line);
	return (-1);
}

static int number_of_sprites(char **file, const char *script)
{
	int i = 1;

	while (file[i] && strncmp(file[i], SCRIPT_TAG, sstrlen(SCRIPT_TAG))) {
		epur_str(file[i]);
		if (strncmp(file[i], LOAD_TAG, sstrlen(LOAD_TAG)) != 0
		    && sstrlen(file[i])) {
			dprintf(2,
				CSFML_ERR
				"[%sWarning%s] Unknown tag <%s> in <%s> "
				"script\n",
				GREEN, RESET, file[i], script);
		}
		++i;
	}
	return (i);
}

static void get_frame_size(const char *format, sfIntRect *frame)
{
	int i;

	i = 0;
	while (format[i] == ' ')
		++i;
	frame->left = atoi(format + i);
	i += kstrlen(format + i, ',') + 1;
	while (format[i] == ' ')
		++i;
	frame->top = atoi(format + i);
	i += intlen(frame->top);
	while (format[i] == ' ')
		++i;
	frame->width = atoi(format + i);
	i += kstrlen(format + i, ',') + 1;
	while (format[i] == ' ')
		++i;
	frame->height = atoi(format + i);
}

static int add_load(const char *format, lsfSprite_t **sprites)
{
	char *filename;
	sfIntRect frame;
	int len;
	int size;

	size = tablen(sprites);
	len = kstrlen(format, ' ');
	filename = strndup(format, len);
	if (sstrlen(format + len) < 8) {
		if (sstrlen(format + len) != 0) {
			dprintf(2, CSFML_ERR "[%sError%s] bad format \"%s\"\n",
				RED, RESET, format - sstrlen(LOAD_TAG));
			return (-1);
		}
		sprites[size] = lsfSprite_create(filename);
	}
	else {
		get_frame_size(format + len, &frame);
		sprites[size] = lsfSprite_create_rect(filename, frame);
	}
	sfree(&filename);
	if (sprites[size] == NULL)
		return (-1);
	return (0);
}

static int use_script(char **file, int nb, lsfSprite_t **sprites)
{
	for (int i = 0; i < nb; ++i)
		if (strncmp(file[i], LOAD_TAG, sstrlen(LOAD_TAG)) == 0) {
			if (add_load(file[i] + sstrlen(LOAD_TAG), sprites)
			    == -1)
				return (-1);
		}
	return (0);
}


/* Load the sprites from the script in "pathname" with the name "script" */
int lsfScript(const char *pathname, const char *script, lsfSprite_t ***ptr)
{
	char **file;
	int line;
	int nb;

	file = load_file(pathname);
	dprintf(2, CSFML_ERR "[%sInfo%s] Loading script %s\"%s\"%s\n", YELLOW, RESET, GREEN,
	       script, RESET);
	if (file == NULL) {
		dprintf(2, CSFML_ERR "[%sError%s] cannot open <%s> script\n",
			RED, RESET, pathname);
		return (-1);
	}
	line = reach_script(file, script);
	if (line == -1) {
		dprintf(2,
			CSFML_ERR
			"[%sError%s] Script <%s> not found in <%s> file\n",
			RED, RESET, script, pathname);
		return (-1);
	}
	nb = number_of_sprites(file + line, script);
	*ptr = calloc(1, sizeof(lsfSprite_t *) * (nb + 1));
	if (ptr == NULL)
		return (-1);
	if (use_script(file + line, nb, *ptr) == -1)
		return (-1);
	sfree_tab(&file);
	dprintf(2, CSFML_ERR "[%sInfo%s] script %s\"%s\"%s successfully loaded\n", YELLOW,
	       RESET, GREEN, script, RESET);
	return (0);
}
