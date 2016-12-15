NAME_CHECKER= checker
NAME_PUSHSWAP= push_swap
SRC_CHECKER= checker.c \
	ft_isint.c \
	ft_isnbr.c \
	ft_b_operations.c \
	ft_a_operations.c \
	ft_operations.c \
	ft_print_stacks.c \
	ft_issorted.c \
	ft_get_op_tab.c
SRC_PUSHSWAP= push_swap.c \
	ft_b_operations.c \
	ft_a_operations.c \
	ft_operations.c \
	ft_print_stacks.c \
	ft_isint.c \
	ft_issorted.c \
	ft_isnbr.c
OBJ_CHECKER= $(SRC_CHECKER:.c=.o)
OBJ_PUSHSWAP= $(SRC_PUSHSWAP:.c=.o)
HDR_PATH= ./libft/includes/
CC= gcc
CC_FLAGS= -Wall -Werror -Wextra

all: $(NAME_CHECKER) $(NAME_PUSHSWAP)

$(NAME_CHECKER): $(OBJ_CHECKER)
	make -C libft/
	$(CC) $(CC_FLAGS) $^ -L./libft -lft -o $(NAME_CHECKER)

$(NAME_PUSHSWAP): $(OBJ_PUSHSWAP)
	make -C libft/
	$(CC) $(CC_FLAGS) $^ -L./libft -lft -o $(NAME_PUSHSWAP)

%.o : %.c
	$(CC) $(CC_FLAGS) $< -c -I$(HDR_PATH)

clean:
	rm -f $(OBJ_CHECKER)
	rm -f $(OBJ_PUSHSWAP)

fclean: clean
	rm -f $(NAME_CHECKER)
	rm -f $(NAME_PUSHSWAP)

re: fclean all
