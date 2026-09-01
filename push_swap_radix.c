/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_strategies.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saydilek <saydilek@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 07:47:20 by saydilek          #+#    #+#             */
/*   Updated: 2026/08/31 07:58:43 by saydilek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void assign_indexes(t_stack *stack)
{
	t_stack *x;
	t_stack *y;
	int index;

	x = stack;
	index = 0;
	while(x)
	{
		y = stack;
		index = 0;
		while(y)
		{
			if(x->value >  y->value)
				index++;
			y = y->next;
		}
		x->index = index;
		x = x->next;
	}
}

int get_max_bits(t_stack *stack)
{
	int max;
	int bits;

	max = 0;
	bits = 0;
	while (stack)
	{
		if(stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	while(max != 0)
	{
		max = max >> 1;
		bits++;
	}
	return bits;
}

void	radix_pass(t_stack **a, t_stack **b, int bit)
{
	int size;
	int i;

	size = ft_lstsize(*a);
	i = 0;
	while(i < size)
	{
		if((((*a)->index >> bit) & 1) == 0)
			pb(b, a);
		else
			ra(a);
		i++;
	}
	while(*b)
		pa(a,b);
}

void radix_sort(t_stack **a, t_stack **b)
{
	int bit;
	int max_bit;

	assign_indexes(*a);
	max_bit = get_max_bits(*a);
	bit = 0;
	while(bit < max_bit)
	{
		radix_pass(a, b, bit);
		bit++;
	}
}