/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguloglu <fguloglu@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 03:04:07 by saydilek          #+#    #+#             */
/*   Updated: 2026/09/02 18:15:20 by fguloglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

typedef struct s_bench
{
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
	int		total;
	double	disorder;
	char	*strategy;
	char	*complexity;
}	t_bench;

int		ft_find_position(t_stack *stack, int target);
void	ft_move_to_top(t_stack **stack, int target);
void	ft_simple_sort(t_stack **a, t_stack **b);

int		ft_chunk_size(int size);
void	ft_bucket_pass(t_stack **a, t_stack **b, int base, int divisor);
void	ft_medium_sort(t_stack **a, t_stack **b);

void	ft_assign_indexes(t_stack *stack);
int		ft_max_bits(t_stack *stack);
void	ft_radix_pass(t_stack **a, t_stack **b, int bit);
void	ft_radix_sort(t_stack **a, t_stack **b);

double	ft_disorder(t_stack *stack);
void	ft_choose_strategy(t_stack **a, t_stack **b);

int		ft_swap(t_stack **stack);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

int		ft_push(t_stack **dest, t_stack **src);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **b, t_stack **a);

int		ft_rotate(t_stack **stack);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);

int		ft_rev_rotate(t_stack **stack);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

t_stack	*ft_new_node(int value);
void	ft_add_front(t_stack **stack, t_stack *new);
void	ft_add_back(t_stack **stack, t_stack *new);
int		ft_lstsize(t_stack *stack);
int		ft_is_sorted(t_stack *stack);

int		ft_strcmp(char *s1, char *s2);
int		ft_get_strategy(char *arg);
void	ft_run_strategy(t_stack **a, t_stack **b, int strategy);

char	**ft_split(char const *s, char c);
void	ft_free_matrix(char **matrix);
void	ft_free_stack(t_stack **stack);
void	ft_error_exit(t_stack **stack, char **matrix);
void	ft_parse_args(int argc, char **argv, t_stack **a, int start);

void	ft_init_bench(t_bench *bench);
void	ft_print_bench(t_bench *bench);
void	ft_count_op(char *op);
t_bench	*ft_get_bench(t_bench *new_bench);

#endif
