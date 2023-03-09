##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## s
##

CC	=	gcc

SRC	=	src/main.c						\
		src/event.c						\
		src/set_up.c					\
		src/get_map.c					\
		src/draw.c

SRC2 =	src/server.c

OBJ     = 	$(SRC:.c=.o)

OBJ2	=	$(SRC2:.c=.o)

TEMP	=	*.gcda *.gcno *.gch

NAME	=	raycaster

NAME2	=	server

LFLAGS	= 	-lcsfml-graphics -lcsfml-window 					\
			-lcsfml-system -lcsfml-audio -L lib/my/ -lmy -lm

CFLAGS	=	-Wall -Wextra

CPPFLAGS	=	-I ./include

all: $(NAME)

$(NAME): $(OBJ) $(OBJ2)
	make -C lib/my/
	$(CC) -o $(NAME) $(OBJ) $(LFLAGS)
	$(CC) -o $(NAME2) $(OBJ2) $(LFLAGS)

unit_tests: fclean libmy.a
	$(CC) tests/units_tests.c libmy.a -lcriterion --coverage

tests_run: unit_tests
	./a.out

clean:
	make clean -C lib/my/
	$(RM) $(OBJ)
	$(RM) $(TEMP)

fclean: clean
	make fclean -C lib/my
	$(RM) $(NAME)

re: fclean all

.PHONY = clean fclean re all
