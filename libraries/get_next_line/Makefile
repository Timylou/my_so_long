NAME		:= libgnl.a

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -g

OBJDIR		:= obj
SRC			:= get_next_line.c get_next_line_utils.c
OBJ			:= $(patsubst %.c, $(OBJDIR)/%.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $@ $^
	@echo "✅ Library created : $(NAME)"

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJDIR)
	# @echo "✅ clean get_next_line done."

fclean: clean
	@rm -f $(NAME)
	# @echo "✅ fclean get_next_line done."

re: fclean all

.PHONY: all clean fclean re
