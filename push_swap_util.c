/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saydilek <saydilek@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 03:06:44 by saydilek          #+#    #+#             */
/*   Updated: 2026/08/31 06:55:46 by saydilek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_new_node(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}

void	ft_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*tmp;

	if (!*stack || !new)
	{
		*stack = new;
		return ;
	}
	tmp = *stack;
	while (tmp->next)
	{
		tmp = (tmp)->next;
	}
	tmp->next = new;
}

void	ft_add_front(t_stack **stack, t_stack *new)
{
	if (!stack || !new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	new->next = *stack;
	*stack = new;
}

int ft_lstsize(t_stack *stack)
{
	int i;

	i = 0;
	while(stack)
	{
		stack= stack->next;
		i++;
	}
	return i;
}

void print_stack(t_stack *stack)
{
	char c;
	while(stack)
	{
		c = stack->value + '0';
		write(1, &c, 1);
		write(1, "\n", 1);
		stack = stack->next;
	}
}