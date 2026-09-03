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

void	ft_assign_indexes(t_stack *stack)
{
	t_stack	*x;
	t_stack	*y;
	int		index;

	x = stack;
	while (x)
	{
		y = stack;
		index = 0;
		while (y)
		{
			if (x->value > y->value)
				index++;
			y = y->next;
		}
		x->index = index;
		x = x->next;
	}
}

int	ft_max_bits(t_stack *stack)
{
	int	max;
	int	bits;

	max = 0;
	bits = 0;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	while (max != 0)
	{
		max = max >> 1;
		bits++;
	}
	return (bits);
}

static int	ft_count_ones(t_stack *stack, int bit)
{
	int	count;

	count = 0;
	while (stack)
	{
		if (((stack->index >> bit) & 1) == 1)
			count++;
		stack = stack->next;
	}
	return (count);
}

void	ft_radix_pass(t_stack **a, t_stack **b, int bit)
{
	int	size;
	int	ones;
	int	ones_done;
	int	i;

	size = ft_lstsize(*a);
	ones = ft_count_ones(*a, bit);
	if (ones == 0 || ones == size)
		return ;
	ones_done = 0;
	i = 0;
	while (i < size && ones_done < ones)
	{
		if ((((*a)->index >> bit) & 1) == 0)
			pb(b, a);
		else
		{
			ra(a);
			ones_done++;
		}
		i++;
	}
	while (*b)
		pa(a, b);
}

void	ft_radix_sort(t_stack **a, t_stack **b)
{
	int	bit;
	int	max_bit;

	ft_assign_indexes(*a);
	max_bit = ft_max_bits(*a);
	bit = 0;
	while (bit < max_bit && !ft_is_sorted(*a))
	{
		ft_radix_pass(a, b, bit);
		bit++;
	}
}
