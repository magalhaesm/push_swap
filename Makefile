NAME = push_swap
BONUS = checker
LIBFT = libft/libft.a

SRC = push_swap.c parse.c stack.c stack_utils.c index.c \
			push.c swap.c rotate.c reverse_rotate.c utils.c   \
			sort.c sort_all.c action_cost.c exec_action.c     \
			output.c errors.c
SRCS = $(addprefix src/, $(SRC))

B_SRC = checker.c parse.c stack.c stack_utils.c index.c \
			push.c swap.c rotate.c reverse_rotate.c utils.c   \
			sort.c sort_all.c action_cost.c exec_action.c     \
			output.c errors.c
B_SRCS = $(addprefix src/, $(B_SRC))

INCLUDE = include/push_swap.h

CFLAGS = -Wall -Werror -Wextra -O3

CYAN	= \33[1;36m
NC		= \033[0m
LOG	= printf "[$(CYAN)INFO$(NC)] %s\n"

all: $(NAME)

bonus: $(BONUS)

$(BONUS):	$(B_SRCS) $(INCLUDE) $(LIBFT)
	@$(LOG) "Compiling $@"
	@$(CC) $(B_SRCS) $(CFLAGS) -I include -I libft -L libft -lft -o $@

$(NAME):	$(SRCS) $(INCLUDE) $(LIBFT)
	@$(LOG) "Compiling $@"
	@$(CC) $(SRCS) $(CFLAGS) -I include -I libft -L libft -lft -o $@

$(LIBFT):
	@make -C libft --no-print-directory

test3:		$(NAME)	
	$(eval ARG = $(shell shuf -i 0-50 -n 3))
	./push_swap $(ARG) | ./checker $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

test5:		$(NAME)	
	$(eval ARG = $(shell shuf -i 0-50 -n 5))
	./push_swap $(ARG) | ./checker $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

test100:	$(NAME)	
	$(eval ARG = $(shell shuf -i 0-1000 -n 100))
	./push_swap $(ARG) | ./checker $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

test500:	$(NAME)	
	$(eval ARG = $(shell shuf -i 0-2000 -n 500))
	./push_swap $(ARG) | ./checker $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

clean:
	@rm -rf $(NAME)
	@$(LOG) "Removing $(NAME)"
	@rm -rf $(BONUS)
	@$(LOG) "Removing $(BONUS)"

fclean: clean

re: fclean all

.PHONY: all clean fclean re bonus
