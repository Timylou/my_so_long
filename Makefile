
NAME 			:= so_long
NAME_BONUS		:= so_long_bonus
CC				:= cc
CFLAGS			:= -Wall -Wextra -Werror -g

DIR_BONUS_SRCS	:= sources/bonus
DIR_SRCS		:= sources/mandatory
DIR_OBJS		:= objs
DIR_LIBFT		:= libraries/libft
DIR_MLX			:= libraries/minilibx-linux

SRCS :=			

BONUS_SRCS :=	

OBJS :=			$(SRCS:.c=.o)
OBJS :=			$(addprefix $(DIR_OBJS)/, $(OBJS))

BONUS_OBJS :=	$(BONUS_SRCS:.c=.o)
BONUS_OBJS :=	$(addprefix $(DIR_OBJS)/, $(BONUS_OBJS))

MLX_LIB			:= $(DIR_MLX)/libmlx.a

INCLUDES		:= -I$(DIR_MLX) -Iincludes

MLX_FLAGS		:= -L$(DIR_MLX) -lmlx -lXext -lX11 -lm -lz

all : $(MLX_LIB) $(NAME)

bonus : $(MLX_LIB) $(NAME_BONUS)

$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(DIR_OBJS)/%_bonus.o: $(DIR_BONUS_SRCS)/%_bonus.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $@
	@echo "✅ Compilation completed: $(NAME)"

$(NAME_BONUS): $(BONUS_OBJS)
	@$(CC) $(CFLAGS) $(BONUS_OBJS) $(MLX_FLAGS) -o $@
	@echo "✅ Compilation completed: $(NAME_BONUS)"

$(MLX_LIB):
	@if [ ! -f $@ ]; then \
		$(MAKE) -s -C $(DIR_MLX) > /dev/null 2>&1; \
		echo "✅ Library created : MLX"; \
	fi

clean :
	@rm -rf $(DIR_OBJS)
	@$(MAKE) -s -C $(DIR_MLX) clean >/dev/null 2>&1 || true
	@echo "✅ clean done."

fclean : clean
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)
	@echo "✅ fclean done."

re : fclean all

rebonus : fclean bonus

norm :
	@norminette includes
	@norminette $(DIR_SRCS)
	@norminette $(DIR_BONUS_SRCS)

.PHONY : all clean fclean re norm bonus


