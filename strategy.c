/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saydilek <saydilek@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 10:36:17 by saydilek          #+#    #+#             */
/*   Updated: 2026/09/03 10:36:17 by saydilek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	ft_get_strategy(char *arg)
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

void	ft_run_strategy(t_stack **a, t_stack **b, int strategy)
{
	if (strategy == 1)
		ft_simple_sort(a, b);
	else if (strategy == 2)
		ft_medium_sort(a, b);
	else if (strategy == 3)
		ft_radix_sort(a, b);
	else
		ft_choose_strategy(a, b);
}
