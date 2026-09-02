/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_selection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saydilek <saydilek@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 03:18:59 by saydilek          #+#    #+#             */
/*   Updated: 2026/09/02 03:18:59 by saydilek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void move_target_to_top(t_stack **stack, int target)
{
    int position;
    int size;

    position = find_position(*stack, target);
    size = ft_lstsize(*stack);

    if(position <= size/2)
    {
        while((*stack)->index != target)
            ra(stack);
    }
    else{
        while((*stack)->index != target)
            rra(stack);
    }
}

void simple_sort(t_stack **a, t_stack **b)
{
    int target;
    int size;
    assign_indexes(*a);

    size = ft_lstsize(*a);
    target = 0;
    while(target < size)
    {
        move_target_to_top(a, target);
        pb(b, a);
        target++;
    }
    while(*b)
    {
        pa(a,b);
    }
}