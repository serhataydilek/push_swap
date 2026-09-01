/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguloglu <fguloglu@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 17:57:57 by fguloglu          #+#    #+#             */
/*   Updated: 2026/09/01 21:37:08 by fguloglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_atol(const char *str, t_stack **stack, char **matrix)
{
	int		i;
	long	result;
	int		number;

	i = 0;
	number = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			number = number * -1;
		i++;
	}
	if (str[i] < '0' || str[i] > '9')
		error_exit(stack, matrix);
	while (str[i] >= '0' && str[i] <= '9')
		result = (result * 10) + (str[i++] - '0');
	if (str[i] != '\0')
		error_exit(stack, matrix);
	if ((result * number) > 2147483647 || (result * number) < -2147483648)
		error_exit(stack, matrix);
	return (result * number);
}

static void check_duplicate(t_stack **stack, char **matrix)
{
	t_stack *tmp;
	int number;
	while (tmp)
	{
		tmp->value == number;
	}
	
}