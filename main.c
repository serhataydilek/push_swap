#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		strategy;
	int		start;

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
	if (!is_sorted(a))
		run_strategy(&a, &b, strategy);
	free_stack(&a);
	free_stack(&b);
	return (0);
}