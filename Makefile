##
## EPITECH PROJECT, 2019
## MUL_my_runner
## File description:
## Makefile
##

NAME = my_runner

LIB = entitylib

FILES = entitylib/basic_entity.c \
	entitylib/bonus.c \
	entitylib/collider.c \
	entitylib/collwith_2.c \
	entitylib/collwith.c \
	entitylib/data_loader.c \
	entitylib/data_saver.c \
	entitylib/data_storage.c \
	entitylib/data_storage_tools.c \
	entitylib/displays.c \
	entitylib/entity.c \
	entitylib/entitylist.c \
	entitylib/g_entity.c \
	entitylib/internal_data.c \
	entitylib/player.c \
	entitylib/score.c \
	entitylib/surface.c \
	entitylib/tools.c \
	entitylib/window_action.c \
	entitylib/window_manager.c \
	load_map.c \
	main.c \
	my_read.c

all :	$(NAME)

$(NAME):
	gcc -o $(NAME) $(FILES) -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

clean:
	rm -f *.o
	rm -f *# *~ ./*/*# ./*/*~ ./*/*/*# ./*/*/*~ 

fclean:	clean
	rm -f $(NAME)

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
	gcc -o $(NAME) $(FILES) -Wall -Wextra -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -pass-exit-codes

valgrind:
	gcc -g3 -o $(NAME) $(FILES) -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

update:
	./mmkfile.sh MUL_my_runner my_runner

$(LIB).a:
	gcc -c $(LIB)/*\.c
	ar rc $(LIB).a *\.o
	rm -f *\.o
