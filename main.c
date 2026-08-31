#include "push_swap.h"

int	main(void)
{
	t_stack *a;
	t_stack *second;
	t_stack *third;
	t_stack *forth;
	a = ft_new_node(3);
	second = ft_new_node(1);
	third = ft_new_node(4);
	forth = ft_new_node(2);
	ft_add_back(&a, second);
	ft_add_back(&a, third);
	ft_add_back(&a, forth);

	t_stack *b;
	t_stack *bs;
	b = ft_new_node(6);
	bs = ft_new_node(5);
	ft_add_back(&b, bs);
	printf("%f\n",compute_disorder(a));
	printf("%f\n",compute_disorder(b));
	assign_indexes(b);
	printf("%d\n", bs->index);
	sa(&a);
	rra(&a);
	sa(&a);
	pa(&a, &b);
	pa(&a, &b);
	ra(&a);
	ra(&a);
	print_stack(a);
	print_stack(b);
	return (0);
}