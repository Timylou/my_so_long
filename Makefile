NAME	=	so_long

CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra -g
CLIBS	=	-lmlx -lXext -lX11 -Lminilibx-linux

SRC		=	so_long.c struct.c input.c image.c background.c tiles.c
OBJ		=	$(SRC:.c=.o)

all		:	$(NAME)

$(NAME)	:	$(OBJ)
	$(CC) $(CFLAGS) $^ -o $@ $(CLIBS)

$(OBJ)	:	$(SRC)
	$(CC) $(CFLAGS) -c $^ $(CLIBS)

norm	:
	@norminette $(SRC)

clean	:
	rm -f $(OBJ)

fclean	:	clean
	rm -f $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re
