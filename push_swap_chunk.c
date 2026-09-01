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

int get_chunk_size(int size)
{
    int chunk;

    chunk = 1;
    while(chunk * chunk < size)
        chunk++;
    return chunk;
}

void push_chunk(t_stack **a, t_stack **b, int start, int end)
{
    int target;
    int pushed;

    target = end - start + 1;
    pushed = 0;
    while(pushed < target)
    {
        if((*a)->index >= start && (*a)->index <= end)
        {
            pb(b,a);
            pushed++;
        }
        else
            ra(a);
    }
}

void	medium_sort(t_stack **a, t_stack **b)
{
	int	size;
	int	chunk_size;
	int	start;
	int	end;

	assign_indexes(*a);
	size = ft_lstsize(*a);
	chunk_size = get_chunk_size(size);
	start = 0;
	end = chunk_size - 1;
	while (start < size)
	{
		if (end >= size)
			end = size - 1;
		push_chunk(a, b, start, end);
		start = end + 1;
		end = start + chunk_size - 1;
	}
}

int find_position(t_stack *stack, int target)
{
    int position;

    position = 0;
    while(stack)
    {
        if(stack->index == target)
            return position;
        position++;
        stack = stack->next;
    }
    return -1;
}

void	move_target_to_top(t_stack **b, int target)
{
    int position;
    int size;

    position = find_position(*b, target);
    size = ft_lstsize(*b);

    if (position == -1)
	    return ;
    if (position <= size / 2)
    {
	    while ((*b)->index != target)
		    rb(b);
    }
    else
    {
	    while ((*b)->index != target)
		    rrb(b);
    }
}