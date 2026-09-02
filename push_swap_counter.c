/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_counter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguloglu <fguloglu@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 17:57:29 by fguloglu          #+#    #+#             */
/*   Updated: 2026/09/02 18:18:28 by fguloglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_bench(t_bench *bench)
{
	if (!bench)
		return ;
	bench->sa = 0;
	bench->sb = 0;
	bench->ss = 0;
	bench->pa = 0;
	bench->pb = 0;
	bench->ra = 0;
	bench->rb = 0;
	bench->rr = 0;
	bench->rra = 0;
	bench->rrb = 0;
	bench->rrr = 0;
	bench->total = 0;
	bench->disorder = 0.0;
	bench->strategy = NULL;
	bench->complexity = NULL;
}

t_bench	*get_bench(t_bench *new_bench)
{
	static t_bench	*bench = NULL;

	if (new_bench)
		bench = new_bench;
	return (bench);
}

static void	count_rotate_op(t_bench *b, char *op)
{
	if (ft_strcmp(op, "ra") == 0)
		b->ra++;
	else if (ft_strcmp(op, "rb") == 0)
		b->rb++;
	else if (ft_strcmp(op, "rr") == 0)
		b->rr++;
	else if (ft_strcmp(op, "rra") == 0)
		b->rra++;
	else if (ft_strcmp(op, "rrb") == 0)
		b->rrb++;
	else if (ft_strcmp(op, "rrr") == 0)
		b->rrr++;
}

void	count_op(char *op)
{
	t_bench	*b;

	b = get_bench(NULL);
	if (!b || !op)
		return ;
	if (ft_strcmp(op, "sa") == 0)
		b->sa++;
	else if (ft_strcmp(op, "sb") == 0)
		b->sb++;
	else if (ft_strcmp(op, "ss") == 0)
		b->ss++;
	else if (ft_strcmp(op, "pa") == 0)
		b->pa++;
	else if (ft_strcmp(op, "pb") == 0)
		b->pb++;
	else
		count_rotate_op(b, op);
	b->total++;
}
