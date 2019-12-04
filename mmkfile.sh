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
	gcc -o \$(NAME) \$(FILES) -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

clean:
	rm -f *.o
	rm -f *# *~ ./*/*# ./*/*~ ./*/*/*# ./*/*/*~ 

fclean:	clean
	rm -f \$(NAME)

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
	gcc -o \$(NAME) \$(FILES) -Wall -Wextra -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

valgrind:
	gcc -g3 -o \$(NAME) \$(FILES) -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

update:
	./mmkfile.sh $1 $2

\$(LIB).a:
	gcc -c \$(LIB)/*\.c
	ar rc \$(LIB).a *\.o
	rm -f *\.o" >> "Makefile"
