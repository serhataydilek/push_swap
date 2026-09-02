/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_benchmark.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguloglu <fguloglu@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 15:50:19 by fguloglu          #+#    #+#             */
/*   Updated: 2026/09/02 17:33:28 by fguloglu         ###   ########.fr       */
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

static void	putstr_err(char *s)
{
	int	len;

	if (!s)
		return ;
	len = 0;
	while (s[len])
		len++;
	write(2, s, len);
}

static void	putnbr_err(long n)
{
	char	c;

	if (n < 0)
	{
		write(2, "-", 1);
		n = -n;
	}
	if (n >= 10)
		putnbr_err(n / 10);
	c = (n % 10) + '0';
	write(2, &c, 1);
}

static void	putdouble_err(double d)
{
	int	int_part;
	int	dec_part;

	int_part = (int)d;
	dec_part = (int)((d - int_part) * 100);
	if (dec_part < 0)
		dec_part = -dec_part;
	putnbr_err(int_part);
	write(2, ".", 1);
	if (dec_part < 10)
		write(2, "0", 1);
	putnbr_err(dec_part);
}

static void	print_ops(t_bench *b)
{
	putstr_err("\n------------------------\n");
	putstr_err("sa: ");
	putnbr_err(b->sa);
	putstr_err(" | sb: ");
	putnbr_err(b->sb);
	putstr_err(" | ss: ");
	putnbr_err(b->ss);
	putstr_err("\npa: ");
	putnbr_err(b->pa);
	putstr_err(" | pb: ");
	putnbr_err(b->pb);
	putstr_err("\nra: ");
	putnbr_err(b->ra);
	putstr_err(" | rb: ");
	putnbr_err(b->rb);
	putstr_err(" | rr: ");
	putnbr_err(b->rr);
	putstr_err("\nrra: ");
	putnbr_err(b->rra);
	putstr_err(" | rrb: ");
	putnbr_err(b->rrb);
	putstr_err(" | rrr: ");
	putnbr_err(b->rrr);
	putstr_err("\n========================\n");
}

void	print_benchmark(t_bench *bench)
{
	if (!bench)
		return ;
	putstr_err("\n=== BENCHMARK REPORT ===\n");
	putstr_err("Disorder: ");
	putdouble_err(bench->disorder);
	putstr_err("\nStrategy: ");
	putstr_err(bench->strategy);
	putstr_err("\nComplexity: ");
	putstr_err(bench->complexity);
	putstr_err("\nTotal Operations: ");
	putnbr_err(bench->total);
	print_ops(bench);
}
