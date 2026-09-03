/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguloglu <fguloglu@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 06:37:22 by saydilek          #+#    #+#             */
/*   Updated: 2026/09/02 18:22:46 by fguloglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rotate(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = NULL;
	ft_add_back(stack, tmp);
	return (1);
}

void	ra(t_stack **a)
{
	if (ft_rotate(a))
	{
		write(1, "ra\n", 3);
		ft_count_op("ra");
	}
}

void	rb(t_stack **b)
{
	if (ft_rotate(b))
	{
		write(1, "rb\n", 3);
		ft_count_op("rb");
	}
}

void	rr(t_stack **a, t_stack **b)
{
	int	x;
	int	y;

	x = ft_rotate(a);
	y = ft_rotate(b);
	if (x || y)
	{
		write(1, "rr\n", 3);
		ft_count_op("rr");
	}
}
