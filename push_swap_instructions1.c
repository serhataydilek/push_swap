/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_instructions1.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saydilek <saydilek@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 03:38:25 by saydilek          #+#    #+#             */
/*   Updated: 2026/08/31 06:25:04 by saydilek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push(t_stack **dest, t_stack **src)
{
	t_stack* tmp;

	if (!dest || !src || !*src)
		return ;
	
	tmp = *src;
	*src = (*src)->next;

	ft_add_front(dest, tmp);
}

void rotate(t_stack **stack)
{
	t_stack *tmp;
	
	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = NULL;
	ft_add_back(stack,tmp);
}

void reverse_rotate(t_stack **stack)
{
	t_stack *last;
	t_stack *prev;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = *stack;
	prev = NULL;
	while(last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
}