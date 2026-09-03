NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = push_swap.c \
	benchmark.c \
	benchmark_counter.c \
	free.c \
	operations_push.c \
	operations_reverse.c \
	operations_rotate.c \
	operations_swap.c \
	parse.c \
	sort_adaptive.c \
	sort_medium.c \
	sort_radix.c \
	sort_simple.c \
	split.c \
	stack_utils.c \
	strategy.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re