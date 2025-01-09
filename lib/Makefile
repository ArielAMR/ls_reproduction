##
## EPITECH PROJECT, 2024
## makefile
## File description:
## lib makefile
##

SRC =	my/my_putchar.c			\
		my/my_put_nbr.c			\
		my/my_putstr.c			\
		my/my_strlen.c 			\
		my/my_revlist.c			\
		src/my_ls.c				\
		src/get_flags.c			\
		src/count_objects.c 	\
		src/get_path.c			\
		src/my_ls_l.c			\
		src/get_blocks.c		\
		src/does_it_exist.c 	\
		src/bubble_sort_time.c	\
		src/get_path_list.c

OBJ = $(SRC:.c=.o)

CFLAGS = -g3

NAME = libmy

all: my_h_cp	$(NAME)	clean

$(NAME): $(OBJ)
	ar rc libmy.a $(OBJ)

my_h_cp:
	cp ../include/*.h my
	cp ../include/*.h src

clean:
	rm */*.o

fclean:
	rm -f libmy.a

re: fclean all
