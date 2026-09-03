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

static void	ft_putnbr(long long n)
{
	char	c;

	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}

void	print_stack(t_stack *stack)
{
	while (stack)
	{
		ft_putnbr(stack->value);
		write(1, "\n", 1);
		stack = stack->next;
	}
}

t_stack	*ft_new_node(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->index = 0;
	node->value = value;
	node->next = NULL;
	return (node);
}

void	ft_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*tmp;

	if (!stack || !new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
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

int is_sorted(t_stack *stack)
{
	while(stack && stack->next)
	{
		if(stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return 1;
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

int	get_strategy(char *arg)
{
	if (ft_strcmp(arg, "--adaptive") == 0)
		return (0);
	if (ft_strcmp(arg, "--simple") == 0)
		return (1);
	if (ft_strcmp(arg, "--medium") == 0)
		return (2);
	if (ft_strcmp(arg, "--complex") == 0)
		return (3);
	return (-1);
}

void	run_strategy(t_stack **a, t_stack **b, int strategy)
{
	if (strategy == 1)
		simple_sort(a, b);
	else if (strategy == 2)
		medium_sort(a, b);
	else if (strategy == 3)
		radix_sort(a, b);
	else
		choose_strategy(a, b);
}