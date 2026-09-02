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

double	compute_disorder(t_stack *stack)
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

void	choose_strategy(t_stack **a, t_stack **b)
{
	double disorder;
	disorder = compute_disorder(*a);
	if (disorder < 0.2)
		(simple_sort(a,b));
	else if (disorder < 0.5)
		(medium_sort(a,b));
	else
		(radix_sort(a,b));
}