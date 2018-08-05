##
## EPITECH PROJECT, 2017
##
## File description:
## makefile
##

NAME		= liblcsfml.so

CC		= gcc

SRCS		= src/clear_win.c
SRCS		+= src/free.c
SRCS		+= src/free_button.c
SRCS		+= src/create_sprite.c
SRCS		+= src/init_csfml.c
SRCS		+= src/get_pixel_color.c
SRCS		+= src/in_rect.c
SRCS		+= src/key_released.c
SRCS		+= src/mouse_pos.c
SRCS		+= src/put_pixel.c
SRCS		+= src/put_png.c
SRCS		+= src/put_sphere.c
SRCS		+= src/put_square.c
SRCS		+= src/put_text.c
SRCS		+= src/quit.c
SRCS		+= src/thread.c
SRCS		+= src/xy_vect.c
SRCS		+= src/distance.c
SRCS		+= src/button.c
SRCS		+= src/poll_event.c
SRCS		+= src/button_display.c
SRCS		+= src/find_by_name.c
SRCS		+= src/load_script.c
SRCS		+= src/draw_line.c

TESTS_SRCS	:= $(SRCS)

OBJS		= $(SRCS:.c=.o)
TESTS_OBJS	= $(TESTS_SRCS:.c=.o)

RM		= rm -f

LIBS		= -lcsfml-window -lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-network
LIBS		+= -llbl-libc

CFLAGS		= -Werror -Wall -Wextra -fPIC -pedantic
CFLAGS		+= -I ./include
LDFLAGS		= -shared

GREEN		= '\033[0;32m'
NO_COLOR	= '\033[0m'

%.o : %.c
	@$ $(CC) $(CFLAGS) -c $< -o $@
	@echo "$(CC) $(CFLAGS) -c $< -o $@ ["$(GREEN)"OK"$(NO_COLOR)"]"
.SUFFIXES: .o .c

all: $(NAME)

$(NAME): $(OBJS)
	@$ $(CC) $(LDFLAGS) $(OBJS) $(LIBS) -o $@
	@echo "$(CC) $(LDFLAGS) $(OBJS) $(LIBS) -o $@ \
	["$(GREEN)"LINKING OK"$(NO_COLOR)"]"

tests_run: $(TESTS_OBJS)
	@$ $(CC) -lcriterion $(TESTS_OBJS) $(LIBS) -o $@
	@echo "$(CC) -lcriterion $(TESTS_OBJS) $(LIBS) -o $@ \
	["$(GREEN)"LINKING OK"$(NO_COLOR)"]"
	./$@
	@$(RM) $@
	@$(RM) $(TESTS_OBJS)

debug: CFLAGS += -g3
debug: re

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

install: re
	@cp $(NAME) /usr/lib/$(NAME) 2> /dev/null || \
	printf "\033[1m\033[31mError : try sudo make install\033[0m\n" && \
	cp include/lcsfml*.h /usr/include/ 2> /dev/null && \
	printf "\033[1m\033[32mLibrary successfull installed !\033[0m\n"

.PHONY: all clean fclean re tests_run debug install
