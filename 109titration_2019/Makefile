##
## EPITECH PROJECT, 2019
## makefile
## File description:
## project
##

NAME	=	109titration

SRC	=	src/main.c 		\
		src/start.c		\
		src/fill_struct.c	\
		src/check_struct.c	\
		src/titration.c		\
		src/compute_deriv.c	\
		src/compute_sec_deriv.c	\
		src/compute_estim.c	\
		src/display.c		\
		src/display_help.c	\
		src/error_handling.c	\
		$(wildcard utils/*.c)

CC	=	gcc

CFLAGS	=	-W -Wextra -Wall

CPPFLAGS	=	-I./include/

CFFLAGS	=	tests/unit_tests.c -I./include --coverage -lcriterion

LDFLAGS	=	-lm

OBJ	=	$(SRC:.c=.o)

all	:	$(OBJ)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(CPPFLAGS) $(LDFLAGS)

debug	:	CFLAGS += -g3
debug	:	re

tests_run	:
		$(CC) -o unit_tests src/*.c $(CFFLAGS)

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)		\
		rm -f *# 		\
		rm -f src/*# 		\
		rm -f include/*# 	\
		rm -f *~ 		\
		rm -f src/*~ 		\
		rm -f include/*~ 	\
		rm -f *.gcda 		\
		rm -f *.gcno		\

re	:	fclean all

.PHONY	:	all debug tests_run clean fclean re
