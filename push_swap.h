/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguloglu <fguloglu@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 03:04:07 by saydilek          #+#    #+#             */
/*   Updated: 2026/09/02 02:00:33 by fguloglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> //delete
//HER FUNCTIONIN BASINA FT YAZ NOLUR NOOLMAZ

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

int find_position(t_stack *stack, int target);
void move_target_to_top(t_stack **stack, int target);
void simple_sort(t_stack **a, t_stack **b);
int		get_chunk_size(int size);
void	bucket_pass(t_stack **a, t_stack **b, int base, int divisor);
void	medium_sort(t_stack **a, t_stack **b);
void assign_indexes(t_stack *stack);
int get_max_bits(t_stack *stack);
void	radix_pass(t_stack **a, t_stack **b, int bit);
void radix_sort(t_stack **a, t_stack **b);
void sa(t_stack **stack);
int ft_lstsize(t_stack *stack);
void	ft_add_front(t_stack **stack, t_stack *new);
void	ft_add_back(t_stack **stack, t_stack *new);
t_stack	*ft_new_node(int value);
void print_stack(t_stack *stack);
int swap(t_stack **stack);
int push(t_stack **dest, t_stack **src);
void pa(t_stack **a, t_stack **b);
void pb(t_stack **b, t_stack **a);
void rr(t_stack **a, t_stack **b);
void rb(t_stack **b);
void ra(t_stack **a);
int rotate(t_stack **stack);
void rrr(t_stack **a, t_stack** b);
void rrb(t_stack **b);
void rra(t_stack **a);
int reverse_rotate(t_stack **stack);
void sa(t_stack **a);
void sb(t_stack **b);
int is_sorted(t_stack *stack);
int		ft_strcmp(char *s1, char *s2);
int		get_strategy(char *arg);
void	run_strategy(t_stack **a, t_stack **b, int strategy);
void ss(t_stack **a, t_stack **b);
double compute_disorder(t_stack* stack);
void	choose_strategy(t_stack **a, t_stack **b);
void assign_indexes(t_stack *stack);
char	**ft_split(char const *s, char c); //Benim eklediklerim
void	free_matrix(char **matrix);
void	free_stack(t_stack **stack);
void	error_exit(t_stack **stack, char **matrix);
void	parse_args(int argc, char **argv, t_stack **a, int start);

#endif