NAME 			:=	so_long
NAME_BONUS		:=	so_long_bonus

CC				:=	cc
CFLAGS			:=	-Wall -Wextra -Werror -g

DIR_BONUS_SRCS	:=	sources/bonus
DIR_SRCS		:=	sources/mandatory
DIR_OBJS		:=	objs
DIR_GNL			:=	libraries/get_next_line
DIR_MLX			:=	libraries/minilibx-linux

SRCS			:=	main.c init.c error.c image.c utils.c background.c input.c loop.c frame.c parse.c player.c \
					tile.c platform.c camera.c
BONUS_SRCS		:=	main.c

OBJS			:=	$(SRCS:.c=.o)
OBJS			:=	$(addprefix $(DIR_OBJS)/, $(OBJS))

BONUS_OBJS		:=	$(BONUS_SRCS:.c=.o)
BONUS_OBJS		:=	$(addprefix $(DIR_OBJS)/, $(BONUS_OBJS))

MLX_LIB			:=	$(DIR_MLX)/libmlx.a
GNL_LIB			:=	$(DIR_GNL)/gnl.a

INCLUDES		:=	-I$(DIR_GNL) -I$(DIR_MLX) -Iincludes

MLX_FLAGS		:=	-L$(DIR_MLX) -lmlx -lXext -lX11 -lm -lz
GNL_FLAGS		:=	-L$(DIR_GNL) -lgnl

all				:	$(GNL_LIB) $(MLX_LIB) $(NAME)

bonus			:	$(GNL_LIB) $(MLX_LIB) $(NAME_BONUS)

$(DIR_OBJS)/%.o	:	$(DIR_SRCS)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(DIR_OBJS)/%_bonus.o	:	$(DIR_BONUS_SRCS)/%_bonus.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME)	:	$(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) $(GNL_FLAGS) -o $@
	@echo "✅ Compilation completed: $(NAME)"

$(NAME_BONUS)	:	$(BONUS_OBJS)
	@$(CC) $(CFLAGS) $(BONUS_OBJS) $(MLX_FLAGS) -o $@
	@echo "✅ Compilation completed: $(NAME_BONUS)"

$(GNL_LIB)	:
	@if [ ! -f $@ ]; then \
		$(MAKE) -s -C $(DIR_GNL) > /dev/null 2>&1; \
		echo "✅ Library created : GET_NEXT_LINE"; \
	fi

$(MLX_LIB)	:
	@if [ ! -f $@ ]; then \
		$(MAKE) -s -C $(DIR_MLX) > /dev/null 2>&1; \
		echo "✅ Library created : MLX"; \
	fi

clean	:
	@rm -rf $(DIR_OBJS)
	@$(MAKE) -s -C $(DIR_GNL) clean >/dev/null 2>&1 || true
	@$(MAKE) -s -C $(DIR_MLX) clean >/dev/null 2>&1 || true
	@echo "✅ clean done."

fclean	:	clean
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)
	@echo "✅ fclean done."

re		:	fclean all

norm :
	@norminette includes
	@norminette $(DIR_SRCS)
	@norminette $(DIR_BONUS_SRCS)

.PHONY : all clean fclean re norm bonus
