cd "$1_2019"
echo -e -n "##
## EPITECH PROJECT, 2019
## $1
## File description:
## Makefile
##

NAME = $2

LIB = entitylib

FILES = " > "Makefile"
tree -i -f "." | cat | grep "\.c" | grep -v "bonus/"| sed -z "s/\n/ @£/g" | sed "s/ @£$//g" | tr "@" "\\" | sed -z "s/£/\n	/g" | sed "s/\.\///g" >> "Makefile"
echo -e "

all :	\$(NAME)

\$(NAME):
	gcc -Ofast -o \$(NAME) \$(FILES) -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -I entitylib/include -I entitylib/collider/include -I entitylib/data_center/include -I entitylib/entities/include -I entitylib/display/include

clean:
	rm -f *.o
	rm -f *# *~ ./*/*# ./*/*~ ./*/*/*# ./*/*/*~

fclean:	clean
	rm -f \$(NAME) vgcore* saves/* screenshoots/*

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
	gcc -Ofast -o \$(NAME) \$(FILES) -Wall -Wextra -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -I entitylib/include -I entitylib/collider/include -I entitylib/data_center/include -I entitylib/entities/include -I entitylib/display/include

valgrind:
	gcc -Ofast -g3 -o \$(NAME) \$(FILES) -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -I entitylib/include -I entitylib/collider/include -I entitylib/data_center/include -I entitylib/entities/include -I entitylib/display/include

update:
	./mmkfile.sh $1 $2

\$(LIB).a:
	gcc -c \$(LIB)/*\.c \$(LIB)/*/*\.c -I entitylib/include -I entitylib/collider/include -I entitylib/data_center/include -I entitylib/entities/include -I entitylib/display/include
	ar rc \$(LIB).a *\.o
	rm -f *\.o" >> "Makefile"
