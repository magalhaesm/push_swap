NAME = push_swap
LIBFT = libft/libft.a

SRC = push_swap.c parse.c stack.c stack_utils.c index.c \
			push.c swap.c rotate.c reverse_rotate.c utils.c   \
			sort.c
SRCS = $(addprefix src/, $(SRC))

INCLUDE = include/push_swap.h

CFLAGS = -Wall -Werror -Wextra -g

all: $(NAME)

$(NAME):	$(SRCS) $(INCLUDE) $(LIBFT)
	@$(CC) $(SRCS) $(CFLAGS) -I include -I libft -L libft -lft -o $@

$(LIBFT):
	@make -C libft --no-print-directory

test:		$(NAME)	
		$(eval ARG = $(shell shuf -i 0-99 -n 8))
		./push_swap $(ARG)

test20:		$(NAME)	
		$(eval ARG = $(shell shuf -i 0-300 -n 20))
		./push_swap $(ARG)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
