/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_reverse_rotate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saydilek <saydilek@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 06:40:16 by saydilek          #+#    #+#             */
/*   Updated: 2026/08/31 06:47:44 by saydilek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int reverse_rotate(t_stack **stack)
{
	t_stack *last;
	t_stack *prev;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	last = *stack;
	prev = NULL;
	while(last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
	return (1);
}

void rra(t_stack **a)
{
	if(reverse_rotate(a))
		write(1, "rra\n", 4);
}

void rrb(t_stack **b)
{
	if(reverse_rotate(b))
		write(1, "rrb\n", 4);
}

void rrr(t_stack **a, t_stack** b)
{
	if(reverse_rotate(a) && reverse_rotate(b))
		write(1, "rrr\n", 4);
}