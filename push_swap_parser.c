/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguloglu <fguloglu@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 17:57:57 by fguloglu          #+#    #+#             */
/*   Updated: 2026/09/02 02:14:02 by fguloglu         ###   ########.fr       */
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

static void	check_duplicate(t_stack **stack, int number, char **matrix)
{
	t_stack	*tmp;

	if (!stack || !*stack)
		return ;
	tmp = *stack;
	while (tmp)
	{
		if (tmp->value == number)
			error_exit(stack, matrix);
		tmp = tmp->next;
	}
}

void	parse_args(int argc, char **argv, t_stack **a, int start)
{
	int		i;
	int		j;
	char	**matrix;
	int		num;
	t_stack	*new_node;

	i = start;
	while (i < argc)
	{
		matrix = ft_split(argv[i], ' ');
		if (!matrix || !matrix[0])
			error_exit(a, matrix);
		j = 0;
		while (matrix[j])
		{
			num = ft_atol(matrix[j], a, matrix);
			check_duplicate(a, num, matrix);
			new_node = ft_new_node(num);
			if (!new_node)
				error_exit(a, matrix);
			ft_add_back(a, new_node);
			j++;
		}
		free_matrix(matrix);
		i++;
	}
}
