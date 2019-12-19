##
## EPITECH PROJECT, 2019
## MUL_my_runner
## File description:
## Makefile
##

NAME = my_runner

LIB = entitylib

FILES = blocs.c \
	editor.c \
	entitylib/collider/collider.c \
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
	entitylib/entities/fired.c \
	entitylib/entities/g_entity.c \
	entitylib/entities/hollow.c \
	entitylib/entities/score.c \
	entitylib/entities/surface.c \
	entitylib/entity.c \
	entitylib/entitylist.c \
	entitylib/player.c \
	entitylib/tools.c \
	get_next_line.c \
	load_map.c \
	main.c \
	mainloop.c \
	menu_bar.c \
	my_init.c \
	my_read.c

all :	$(NAME)

$(NAME):
	gcc -Ofast -o $(NAME) $(FILES) -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -I entitylib/include -I entitylib/collider/include -I entitylib/data_center/include -I entitylib/entities/include -I entitylib/display/include

clean:
	rm -f *.o
	rm -f *# *~ ./*/*# ./*/*~ ./*/*/*# ./*/*/*~

fclean:	clean
	rm -f $(NAME) vgcore* saves/* screenshoots/*

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
	gcc -Ofast -o $(NAME) $(FILES) -Wall -Wextra -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -I entitylib/include -I entitylib/collider/include -I entitylib/data_center/include -I entitylib/entities/include -I entitylib/display/include

valgrind:
	gcc -Ofast -g3 -o $(NAME) $(FILES) -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -I entitylib/include -I entitylib/collider/include -I entitylib/data_center/include -I entitylib/entities/include -I entitylib/display/include

gdb:
	clear
	gcc -g3 -o $(NAME) $(FILES) -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -I entitylib/include -I entitylib/collider/include -I entitylib/data_center/include -I entitylib/entities/include -I entitylib/display/include -Wall -Wextra

update:
	./mmkfile.sh MUL_my_runner my_runner

$(LIB).a:
	gcc -c $(LIB)/*\.c $(LIB)/*/*\.c -I entitylib/include -I entitylib/collider/include -I entitylib/data_center/include -I entitylib/entities/include -I entitylib/display/include
	ar rc $(LIB).a *\.o
	rm -f *\.o
