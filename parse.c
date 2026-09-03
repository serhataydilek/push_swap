/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguloglu <fguloglu@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 17:57:57 by fguloglu          #+#    #+#             */
/*   Updated: 2026/09/03 15:24:56 by fguloglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_get_sign(const char *str, int *i)
{
	int	sign;

	sign = 1;
	while (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
		(*i)++;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

static int	ft_atol(const char *str, t_stack **stack, char **matrix)
{
	int			i;
	int			sign;
	int			digit;
	long long	result;
	long long	limit;

	i = 0;
	sign = ft_get_sign(str, &i);
	result = 0;
	if (str[i] < '0' || str[i] > '9')
		ft_error_exit(stack, matrix);
	limit = 2147483647LL;
	if (sign == -1)
		limit = 2147483648LL;
	while (str[i] >= '0' && str[i] <= '9')
	{
		digit = str[i++] - '0';
		if (result > (limit - digit) / 10)
			ft_error_exit(stack, matrix);
		result = (result * 10) + digit;
	}
	if (str[i] != '\0')
		ft_error_exit(stack, matrix);
	return ((int)(result * sign));
}

static void	ft_check_duplicate(t_stack **stack, int num, char **matrix)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp)
	{
		if (tmp->value == num)
			ft_error_exit(stack, matrix);
		tmp = tmp->next;
	}
}

static void	ft_add_values(char **matrix, t_stack **a)
{
	t_stack	*node;
	int		num;
	int		i;

	i = 0;
	while (matrix[i])
	{
		num = ft_atol(matrix[i], a, matrix);
		ft_check_duplicate(a, num, matrix);
		node = ft_new_node(num);
		if (!node)
			ft_error_exit(a, matrix);
		ft_add_back(a, node);
		i++;
	}
}

void	ft_parse_args(int argc, char **argv, t_stack **a, int start)
{
	char	**matrix;

	while (start < argc)
	{
		matrix = ft_split(argv[start], ' ');
		if (!matrix || !matrix[0])
			ft_error_exit(a, matrix);
		ft_add_values(matrix, a);
		ft_free_matrix(matrix);
		start++;
	}
}
