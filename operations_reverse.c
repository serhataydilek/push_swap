/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_reverse_rotate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguloglu <fguloglu@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 06:40:16 by saydilek          #+#    #+#             */
/*   Updated: 2026/09/02 18:22:46 by fguloglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rev_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*prev;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	last = *stack;
	prev = NULL;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
	return (1);
}

void	rra(t_stack **a)
{
	if (ft_rev_rotate(a))
	{
		write(1, "rra\n", 4);
		ft_count_op("rra");
	}
}

void	rrb(t_stack **b)
{
	if (ft_rev_rotate(b))
	{
		write(1, "rrb\n", 4);
		ft_count_op("rrb");
	}
}

void	rrr(t_stack **a, t_stack **b)
{
	int	x;
	int	y;

	x = ft_rev_rotate(a);
	y = ft_rev_rotate(b);
	if (x || y)
	{
		write(1, "rrr\n", 4);
		ft_count_op("rrr");
	}
}
