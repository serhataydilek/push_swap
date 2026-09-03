
// int	main(int argc, char **argv)
// {
// 	t_stack	*a;
// 	t_stack	*b;
// 	int		strategy;
// 	int		start;

// 	a = NULL;
// 	b = NULL;
// 	if (argc < 2)
// 		return (0);
// 	strategy = get_strategy(argv[1]);
// 	if (strategy == -1)
// 	{
// 		strategy = 0;
// 		start = 1;
// 	}
// 	else
// 		start = 2;
// 	parse_args(argc, argv, &a, start);
// 	if (!is_sorted(a))
// 		run_strategy(&a, &b, strategy);
// 	free_stack(&a);
// 	free_stack(&b);
// 	return (0);
// }

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		strategy;
	int		start;
	int		bench_mode;
	t_bench	bench;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	start = 1;
	bench_mode = 0;
	if (ft_strcmp(argv[start], "--bench") == 0)
	{
		bench_mode = 1;
		start++;
	}
	if (start == argc)
		error_exit(&a, NULL);
	strategy = get_strategy(argv[start]);
	if (strategy == -1)
		strategy = 0;
	else
		start++;
	parse_args(argc, argv, &a, start);
	if (!a)
		return (0);
	if (bench_mode)
	{
		init_bench(&bench);
		get_bench(&bench);
		bench.disorder = compute_disorder(a);
	}
	if (!is_sorted(a))
		run_strategy(&a, &b, strategy);
	if (bench_mode)
	{
		if (strategy == 1)
		{
			bench.strategy = "Simple Sort";
			bench.complexity = "O(n^2)";
		}
		else if (strategy == 2)
		{
			bench.strategy = "Medium Sort";
			bench.complexity = "O(n*sqrt(n))";
		}
		else if (strategy == 3)
		{
			bench.strategy = "Complex Sort";
			bench.complexity = "O(n*log(n))";
		}
		else
	{
		bench.strategy = "Adaptive";
		if (bench.disorder < 0.2)
			bench.complexity = "O(n^2)";
		else if (bench.disorder < 0.5)
			bench.complexity = "O(n*sqrt(n))";
		else
			bench.complexity = "O(n*log(n))";
	}
		print_benchmark(&bench);
	}
	free_stack(&a);
	free_stack(&b);
	return (0);
}