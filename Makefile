##
## EPITECH PROJECT, 2019
## MUL_my_runner
## File description:
## Makefile
##

NAME = my_runner

LIB = entitylib

FILES = entitylib/collider/collider.c \
	entitylib/collider/collwith_2.c \
	entitylib/collider/collwith.c \
	entitylib/data_center/data_loader.c \
	entitylib/data_center/data_saver.c \
	entitylib/data_center/data_storage.c \
	entitylib/data_center/data_storage_tools.c \
	entitylib/data_center/internal_data.c \
	entitylib/display/displays.c \
	entitylib/display/display_thread.c \
	entitylib/display/window_action.c \
	entitylib/display/window_manager.c \
	entitylib/entities/bonus.c \
	entitylib/entities/g_entity.c \
	entitylib/entities/score.c \
	entitylib/entities/surface.c \
	entitylib/entity.c \
	entitylib/entitylist.c \
	entitylib/player.c \
	entitylib/tools.c \
	load_map.c \
	main.c \
	mainloop.c \
	my_read.c

all :	$(NAME)

$(NAME):
	gcc -o $(NAME) $(FILES) -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -I entitylib/include -I entitylib/collider/include -I entitylib/data_center/include -I entitylib/entities/include -I entitylib/display/include

clean:
	rm -f *.o
	rm -f *# *~ ./*/*# ./*/*~ ./*/*/*# ./*/*/*~

fclean:	clean
	rm -f $(NAME) vgcore* saves/*

re:	fclean all

prepush:	fclean
	git add --all
	git status

tree:	prepush
	tree -a -I .git

push:	prepush
	git commit -m 'auto-sync with master'
	git push origin master

pull:
	git pull origin master

sync:	pull	push

debug:
	clear
	gcc -o $(NAME) $(FILES) -Wall -Wextra -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -I entitylib/include -I entitylib/collider/include -I entitylib/data_center/include -I entitylib/entities/include -I entitylib/display/include

valgrind:
	gcc -g3 -o $(NAME) $(FILES) -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -I entitylib/include -I entitylib/collider/include -I entitylib/data_center/include -I entitylib/entities/include -I entitylib/display/include

update:
	./mmkfile.sh MUL_my_runner my_runner

$(LIB).a:
	gcc -c $(LIB)/*\.c $(LIB)/*/*\.c -I entitylib/include -I entitylib/collider/include -I entitylib/data_center/include -I entitylib/entities/include -I entitylib/display/include
	ar rc $(LIB).a *\.o
	rm -f *\.o
