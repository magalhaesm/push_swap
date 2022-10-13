NAME = push_swap
LIBFT = libft/libft.a

SRC = push_swap.c parse.c stack.c stack_utils.c index.c \
			push.c swap.c rotate.c reverse_rotate.c utils.c   \
			sort.c sort_all.c action_cost.c exec_action.c
SRCS = $(addprefix src/, $(SRC))

INCLUDE = include/push_swap.h

CFLAGS = -Wall -Werror -Wextra -g

all: $(NAME)

$(NAME):	$(SRCS) $(INCLUDE) $(LIBFT)
	@$(CC) $(SRCS) $(CFLAGS) -I include -I libft -L libft -lft -o $@

$(LIBFT):
	@make -C libft --no-print-directory

test3:		$(NAME)	
		$(eval ARG = $(shell shuf -i 0-50 -n 3))
		./push_swap $(ARG) | ./checker_linux $(ARG)
		@echo -n "Instructions: "
		@./push_swap $(ARG) | wc -l

test5:		$(NAME)	
		$(eval ARG = $(shell shuf -i 0-50 -n 5))
		./push_swap $(ARG) | ./checker_linux $(ARG)
		@echo -n "Instructions: "
		@./push_swap $(ARG) | wc -l

test100:	$(NAME)	
		$(eval ARG = $(shell shuf -i 0-1000 -n 100))
		./push_swap $(ARG) | ./checker_linux $(ARG)
		@echo -n "Instructions: "
		@./push_swap $(ARG) | wc -l

test500:	$(NAME)	
		$(eval ARG = $(shell shuf -i 0-2000 -n 500))
		./push_swap $(ARG) | ./checker_linux $(ARG)
		@echo -n "Instructions: "
		@./push_swap $(ARG) | wc -l

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
