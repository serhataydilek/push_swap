/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguloglu <fguloglu@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 03:38:25 by saydilek          #+#    #+#             */
/*   Updated: 2026/09/02 18:22:46 by fguloglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int push(t_stack **dest, t_stack **src)
{
	t_stack* tmp;

	if (!dest || !src || !*src)
		return (0);
	
	tmp = *src;
	*src = (*src)->next;
	tmp->next = NULL;
	ft_add_front(dest, tmp);
	return (1);
}

void pa(t_stack **a, t_stack **b)
{
	if (push(a, b))
	{
		write(1, "pa\n", 3);
		count_op("pa");
	}
}

void pb(t_stack **b, t_stack **a)
{
	if (push(b, a))
	{
		write(1, "pb\n", 3);
		count_op("pb");
	}
}

