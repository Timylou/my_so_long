NAME	=	so_long

CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra -g
CLIBS	=	-lmlx_Linux -lXext -lX11 -Lminilibx-linux

SRC		=	so_long.c struct.c image.c input.c map.c parse.c error.c \
			translate.c player.c print.c flood_fill.c \
			get_next_line.c get_next_line_utils.c

OBJ		=	$(SRC:.c=.o)

all		:	$(NAME)

$(NAME)	:	$(OBJ)
	$(CC) $(CFLAGS) $^ -o $@ $(CLIBS)

$(OBJ)	:	$(SRC)
	$(CC) $(CFLAGS) -c $^

norm	:
	@norminette $(SRC)

clean	:
	rm -f $(OBJ)

fclean	:	clean
	rm -f $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re
