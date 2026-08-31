/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_instructions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saydilek <saydilek@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 03:23:33 by saydilek          #+#    #+#             */
/*   Updated: 2026/08/31 03:36:55 by saydilek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_stack **stack)
{
	t_stack *first;
	t_stack *second;
	
	if(!stack || !*stack || !(*stack)->next)//look at this
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void sa(t_stack **a)
{
	swap(a);
}

void sa(t_stack **b)
{
	swap(b);
}

void ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
}