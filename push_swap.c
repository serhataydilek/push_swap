/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saydilek <saydilek@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 10:45:34 by saydilek          #+#    #+#             */
/*   Updated: 2026/09/03 10:45:34 by saydilek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_setup(int argc, char **argv, t_stack **a, int *bench_mode)
{
	int	start;
	int	strategy;

	start = 1;
	*bench_mode = 0;
	if (ft_strcmp(argv[start], "--bench") == 0)
	{
		*bench_mode = 1;
		start++;
	}
	if (start == argc)
		ft_error_exit(a, NULL);
	strategy = ft_get_strategy(argv[start]);
	if (strategy == -1)
		strategy = 0;
	else
		start++;
	if (start == argc)
		ft_error_exit(a, NULL);
	ft_parse_args(argc, argv, a, start);
	return (strategy);
}

static void	ft_bench_start(t_bench *bench, t_stack *a)
{
	ft_init_bench(bench);
	ft_get_bench(bench);
	bench->disorder = ft_disorder(a);
}

static void	ft_set_adaptive_bench(t_bench *bench)
{
	bench->strategy = "Adaptive";
	if (bench->disorder < 0.2)
		bench->complexity = "O(n^2)";
	else if (bench->disorder < 0.5)
		bench->complexity = "O(n*sqrt(n))";
	else
		bench->complexity = "O(n*log(n))";
}

static void	ft_bench_end(t_bench *bench, int strategy)
{
	if (strategy == 1)
	{
		bench->strategy = "Simple Sort";
		bench->complexity = "O(n^2)";
	}
	else if (strategy == 2)
	{
		bench->strategy = "Medium Sort";
		bench->complexity = "O(n*sqrt(n))";
	}
	else if (strategy == 3)
	{
		bench->strategy = "Complex Sort";
		bench->complexity = "O(n*log(n))";
	}
	else
		ft_set_adaptive_bench(bench);
	ft_print_bench(bench);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_bench	bench;
	int		strategy;
	int		bench_mode;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	strategy = ft_setup(argc, argv, &a, &bench_mode);
	if (bench_mode)
		ft_bench_start(&bench, a);
	if (!ft_is_sorted(a))
		ft_run_strategy(&a, &b, strategy);
	if (bench_mode)
		ft_bench_end(&bench, strategy);
	ft_free_stack(&a);
	ft_free_stack(&b);
	return (0);
}
