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
		x = x->next;
	}
}