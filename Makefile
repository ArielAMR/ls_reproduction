##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## root Makefile
##

all: crlib	cmp

crlib:
	make -C lib/ re

cmp:
	gcc -o my_ls main.c lib/src/my_ls.c -Iinclude/ -Llib/ -lmy \
	-Wall -Wextra

functionnal_tests: crlib
	bash tests/functionnal_tests.sh

clean:
	rm my_ls

fclean: clean

re: fclean all
