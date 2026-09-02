#include "push_swap.h"

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
	t_bench	bench;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	strategy = get_strategy(argv[1]);
	if (strategy == -1)
	{
		strategy = 0;
		start = 1;
	}
	else
		start = 2;
	parse_args(argc, argv, &a, start);
	if (!a)
		return (0);
	init_bench(&bench);
	get_bench(&bench);
	bench.disorder = compute_disorder(a);
	if (!is_sorted(a))
		run_strategy(&a, &b, strategy);
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
		bench.complexity = "Dynamic";
	}
	print_benchmark(&bench);
	free_stack(&a);
	free_stack(&b);
	return (0);
}