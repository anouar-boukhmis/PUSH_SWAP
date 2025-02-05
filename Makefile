NAME = push_swap
NAME_BNS = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = push_swap.c push_swap_utile.c operations.c algo.c algo_2.c check_cmbine.c \
	push_swap_utile_2.c push_swap_utile_3.c push_swap_utile_4.c push_swap_utile_5.c \
	algo_3.c operation_2.c operation_3.c
SRC_BNS = bonus/checker_bonus.c bonus/get_next_line_bonus.c bonus/get_next_line_utils_bonus.c bonus/operation_bonus_2.c \
	bonus/operation_bonus0.c bonus/operations_bonus.c bonus/push_swap_utile_2_bonus.c \
	bonus/push_swap_utile_3_bonus.c bonus/push_swap_utile_4_bonus.c bonus/push_swap_utile_5_bonus.c \
	bonus/push_swap_utile_bonus.c bonus/check_sort_bonus.c
OBJ = $(SRC:.c=.o)
OBJ_BNS = $(SRC_BNS:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(NAME_BNS)

$(NAME_BNS): $(OBJ_BNS)
	$(CC) $(CFLAGS) -o $(NAME_BNS) $(OBJ_BNS)
bonus/%.o: bonus/%.c bonus/push_swap_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJ) $(OBJ_BNS)
fclean: clean
	rm -f $(NAME)  $(NAME_BNS)
re: fclean all


.PHONY: clean