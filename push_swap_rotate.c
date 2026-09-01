/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saydilek <saydilek@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 06:37:22 by saydilek          #+#    #+#             */
/*   Updated: 2026/08/31 06:56:28 by saydilek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int rotate(t_stack **stack)
{
	t_stack *tmp;
	
	if (!stack || !*stack || !(*stack)->next)
		return (0);
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = NULL;
	ft_add_back(stack,tmp);
	return (1);
}

void ra(t_stack **a)
{
	if(rotate(a))
		write(1, "ra\n", 3);
}

void rb(t_stack **b)
{
	if(rotate(b))
		write(1, "rb\n", 3);
}

void rr(t_stack **a, t_stack **b)
{
	int x;
	int y;

	x = rotate(a);
	y = rotate(b);
	if(x || y)
		write(1, "rr\n", 3);
}