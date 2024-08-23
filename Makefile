NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRC = ft_atol.c ft_errors.c ft_sort_stack_complex_utils.c ft_sort_stock_costs.c ft_free.c ft_init_stack.c ft_not_stack_sorted.c ft_pa_pb.c ft_ra_rb_rr.c ft_rra_rrb_rrr.c ft_sa_sb_ss.c ft_sort_stack_complex.c ft_sorted_three.c ft_split_stack.c ft_stack_len.c ft_target_node.c main.c


OBJS = $(SRC:.c=.o) 

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< 

clean:
	$(MAKE) clean -C
	rm -f $(OBJS)

fclean: clean
	$(MAKE) fclean -C
	rm -f $(NAME)

re: fclean all

.PHONY: all check show clean re
