/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_compute.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saydilek <saydilek@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 07:25:54 by saydilek          #+#    #+#             */
/*   Updated: 2026/08/31 07:55:10 by saydilek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	ft_disorder(t_stack *stack)
{
	t_stack	*x;
	t_stack	*y;
	double	error;
	double	total;

	total = 0;
	error = 0;
	x = stack;
	while (x)
	{
		y = x->next;
		while (y)
		{
			if (x->value > y->value)
				error++;
			total++;
			y = y->next;
		}
		x = x->next;
	}
	if (total == 0)
		return (0);
	return (error / total);
}

void	ft_choose_strategy(t_stack **a, t_stack **b)
{
	double	disorder;

	if (ft_is_sorted(*a))
		return ;
	disorder = ft_disorder(*a);
	if (disorder < 0.2)
		ft_simple_sort(a, b);
	else if (disorder < 0.5)
		ft_medium_sort(a, b);
	else
		ft_radix_sort(a, b);
}
