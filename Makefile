NAME = push_swap
LIBFT = libft/libft.a

SRC = push_swap.c
SRCS = $(addprefix src/, $(SRC))

INCLUDE = include/push_swap.h

CFLAGS = -Wall -Werror -Wextra -g

all: $(NAME)

$(NAME):	$(SRCS) $(INCLUDE) $(LIBFT)
	@$(CC) $(SRCS) $(CFLAGS) -I include -I libft -L libft -lft -o $@

$(LIBFT):
	@make -C libft --no-print-directory

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
