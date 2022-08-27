/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_nums.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajrhou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 16:16:24 by ayajrhou          #+#    #+#             */
/*   Updated: 2021/09/28 16:16:29 by ayajrhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_3_num(t_node *stack_a, int fr)
{
	int		sec;
	int		th;
	t_node	*start;

	start = stack_a;
	fr = start->value;
	sec = start->next->value;
	th = start->next->next->value;
	if (fr > sec && fr < th && sec < th)
		stack_a = swap_a(stack_a);
	else if (fr > sec && fr > th && sec > th)
	{
		stack_a = swap_a(stack_a);
		stack_a = rotate_reverse_a(stack_a);
	}
	else if (fr > sec && fr > th && sec < th)
		stack_a = rotate_a(start);
	else if (fr < sec && fr < th && sec > th)
	{
		stack_a = swap_a(stack_a);
		stack_a = rotate_a(stack_a);
	}
	else if (fr < sec && fr > th && sec > th)
		stack_a = rotate_reverse_a(stack_a);
	return (stack_a);
}

t_node	*ft_5_num(t_node *stack_a, t_node *stack_b)
{
	int	ft;

	ft = 0;
	push_b(&stack_b, &stack_a);
	push_b(&stack_b, &stack_a);
	if (a_is_sorted(stack_a, 0))
		stack_a = ft_3_num(stack_a, ft);
	stack_a = ft_comparing_stack(stack_a, stack_b);
	return (stack_a);
}

t_node	*ft_4_num(t_node *stack_a, t_node *stack_b, int i)
{
	int	c;
	int	b;

	b = i;
	c = i;
	while (i)
	{
		if (stack_a->value == 0)
		{
			push_b(&stack_b, &stack_a);
			c--;
		}
		if (stack_a->value == 1 && b == 5)
		{
			push_b(&stack_b, &stack_a);
			c--;
		}
		stack_a = rotate_reverse_a(stack_a);
		i--;
	}
	stack_a = ft_3_num(stack_a, i);
	ft_check_stackb(&stack_a, &stack_b, b);
	return (stack_a);
}

t_node	*ft_comparing_stack(t_node *stack_a, t_node *stack_b)
{
	t_node	*tmp;

	tmp = stack_a;
	if (stack_b->value > stack_b->next->value)
		stack_b = rotate_b(stack_b);
	if (stack_b->value < stack_a->value)
		push_a(&stack_b, &stack_a);
	stack_a = rotate_reverse_a(stack_a);
	while (stack_a->next)
	{
		if (stack_b->value == stack_a->value - 1)
			push_a(&stack_b, &stack_a);
		else
			stack_a = rotate_reverse_a(stack_a);
		stack_a = stack_a->next;
	}
	return (tmp);
}

void	ft_check_stackb(t_node **stack_a, t_node **stack_b, int c)
{
	if (c == 5)
	{
		if ((*stack_b)->value < (*stack_b)->next->value)
			*stack_b = rotate_b(*stack_b);
		push_a(stack_b, stack_a);
		push_a(stack_b, stack_a);
	}
	else
		push_a(stack_b, stack_a);
}
