/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_selection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saydilek <saydilek@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 03:18:59 by saydilek          #+#    #+#             */
/*   Updated: 2026/09/02 03:18:59 by saydilek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_position(t_stack *stack, int target)
{
	int	position;

	position = 0;
	while (stack)
	{
		if (stack->index == target)
			return (position);
		position++;
		stack = stack->next;
	}
	return (-1);
}

void	ft_move_to_top(t_stack **stack, int target)
{
	int	position;
	int	size;

	position = ft_find_position(*stack, target);
	size = ft_lstsize(*stack);
	if (position <= 0)
		return ;
	if (position == 1)
		sa(stack);
	else if (position <= size / 2)
	{
		while ((*stack)->index != target)
			ra(stack);
	}
	else
	{
		while ((*stack)->index != target)
			rra(stack);
	}
}

void	ft_simple_sort(t_stack **a, t_stack **b)
{
	int	target;
	int	size;

	ft_assign_indexes(*a);
	size = ft_lstsize(*a);
	target = 0;
	while (target < size - 1)
	{
		if (ft_is_sorted(*a))
			break ;
		ft_move_to_top(a, target);
		if (ft_is_sorted(*a))
			break ;
		pb(b, a);
		target++;
	}
	while (*b)
		pa(a, b);
}
