##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## s
##

CC	=	gcc

SRC	= 	my_compute_power_rec.c 	\
		my_compute_square_root.c	\
		my_find_prime_sup.c 		\
		my_getnbr.c 				\
		my_isneg.c 				\
		my_is_prime.c 			\
		my_putchar.c  			\
		my_put_nbr.c 			\
		my_putstr.c   			\
		my_show_word_array.c 	\
		my_sort_int_array.c 		\
		my_strcapitalize.c 		\
		my_strcat.c 				\
		my_strcmp.c 				\
		my_strcpy.c  			\
		my_str_isalpha.c 		\
		my_str_isnum.c 			\
		my_str_isprintable.c 	\
		my_str_isupper.c 		\
		my_strlen.c 				\
		my_strlowcase.c 			\
		my_strncmp.c 			\
		my_strncpy.c 			\
		my_strstr.c 				\
		my_strupcase.c 			\
		my_swap.c				\
		my_put_unsnbr.c			\
		my_put_nbr_virgule.c		\
		my_printf.c				\
		funct_flag.c				\
		my_put_unsnbr.c			\
		funct2.c					\
		funct3.c					\
		base_funct.c				\
		funct4.c					\
		malloc_2d_array.c			\
		my_str_to_word_array.c		\
		my_len_of_array.c			\
		reduce_len_of_str.c			\
		free_array.c

OBJ     = 	$(SRC:.c=.o)

TEMP	=	*.gcda *.gcno *.gch

NAME	=	libmy.a

CFLAGS	=	-Wall -Wextra

all:$(NAME)

$(NAME):        $(OBJ)
	ar rc $(NAME) $(OBJ)

unit_tests: re
	$(CC) tests/units_tests.c libmy.a -lcriterion --coverage

tests_run: unit_tests
	./a.out
clean:
	$(RM) $(OBJ)
	$(RM) $(TEMP)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY = clean fclean re
