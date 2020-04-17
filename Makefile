##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Shared library
##

CC 		= 	gcc

SRC		=	src/malloc.c		\
			src/realloc.c		\
			src/calloc.c		\
			src/free.c			\
			src/split.c			\
			src/put_pointer.c	\
			src/my_put_nbr.c

NAME	=	libmy_malloc.so

OBJ		=	$(SRC:.c=.o)

CFLAGS	+=	-W -Wall -Wextra -fPIC -Iinclude/

LDFLAGS	=	-shared

all: 		$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(LDFLAGS) -o $(NAME) $(OBJ)

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re