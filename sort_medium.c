/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_chunk.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saydilek <saydilek@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 00:21:27 by saydilek          #+#    #+#             */
/*   Updated: 2026/09/02 00:21:27 by saydilek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_chunk_size(int size)
{
	int	chunk;

	chunk = 1;
	while (chunk * chunk < size)
		chunk++;
	return (chunk);
}

void	ft_bucket_pass(t_stack **a, t_stack **b, int base, int divisor)
{
	int	bucket;
	int	size;
	int	i;
	int	match;

	bucket = 0;
	while (bucket < base - 1)
	{
		size = ft_lstsize(*a);
		i = 0;
		while (i < size)
		{
			match = (((*a)->index / divisor) % base == bucket);
			if (match && !(bucket == base - 2 && i == size - 1))
				pb(b, a);
			else if (!match)
				ra(a);
			i++;
		}
		bucket++;
	}
	while (*b)
		pa(a, b);
}

void	ft_medium_sort(t_stack **a, t_stack **b)
{
	int	size;
	int	base;

	ft_assign_indexes(*a);
	size = ft_lstsize(*a);
	if (size < 2)
		return ;
	base = ft_chunk_size(size);
	ft_bucket_pass(a, b, base, 1);
	if (!ft_is_sorted(*a))
		ft_bucket_pass(a, b, base, base);
}
