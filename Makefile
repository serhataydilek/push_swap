NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c \
	push_swap_benchmark.c \
	push_swap_bucket.c \
	push_swap_compute.c \
	push_swap_counter.c \
	push_swap_free.c \
	push_swap_parser.c \
	push_swap_push.c \
	push_swap_radix.c \
	push_swap_reverse_rotate.c \
	push_swap_rotate.c \
	push_swap_selection.c \
	push_swap_split.c \
	push_swap_swap.c \
	push_swap_util.c

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