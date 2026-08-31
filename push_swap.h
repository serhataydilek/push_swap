/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saydilek <saydilek@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 03:04:07 by saydilek          #+#    #+#             */
/*   Updated: 2026/08/31 06:53:01 by saydilek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> //delete


typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;



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
void ss(t_stack **a, t_stack **b);

#endif