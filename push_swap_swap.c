/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saydilek <saydilek@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 03:23:33 by saydilek          #+#    #+#             */
/*   Updated: 2026/08/31 06:54:59 by saydilek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int swap(t_stack **stack)
{
	t_stack *first;
	t_stack *second;
	
	if(!stack || !*stack || !(*stack)->next)//look at this
		return (0);
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
	return (1);
}

void sa(t_stack **a)
{
	if(swap(a))
		write(1, "sa\n", 3);
}

void sb(t_stack **b)
{
	if(swap(b))
		write(1, "sb\n", 3);
}

void ss(t_stack **a, t_stack **b)
{
	int x;
	int y;

	x = swap(a);
	y = swap(b); 
	if(x || y)
		write(1, "ss\n", 3);
}