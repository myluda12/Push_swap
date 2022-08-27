/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajrhou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 16:14:33 by ayajrhou          #+#    #+#             */
/*   Updated: 2021/09/28 16:14:39 by ayajrhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_node **stack_b, t_node **stack_a)
{
	t_node	*tmp_a;
	t_node	*tmp_b;

	ft_putstr("pb\n");
	tmp_a = (*stack_a)->next;
	tmp_b = (*stack_a);
	tmp_b->next = *(stack_b);
	(*stack_b) = tmp_b;
	(*stack_a) = tmp_a;
}

void	push_a(t_node **stack_b, t_node **stack_a)
{
	t_node	*tmp_a;
	t_node	*tmp_b;

	ft_putstr("pa\n");
	tmp_b = (*stack_b)->next;
	tmp_a = (*stack_b);
	tmp_a->next = *(stack_a);
	(*stack_a) = tmp_a;
	(*stack_b) = tmp_b;
}

int	bits_calculator(int size)
{
	int		max_value;
	int		c;

	c = 0;
	max_value = size - 1;
	while (max_value)
	{
		c++;
		max_value >>= 1;
	}
	return (c);
}

void	ft_sort_binary(t_node **stack_a, t_node **stack_b, int i, int size)
{
	int	j;

	j = size;
	while (j--)
	{
		if (!((*stack_a)->value >> i & 1))
			push_b(stack_b, stack_a);
		else
			(*stack_a) = rotate_a(*stack_a);
	}
}

void	ft_bit_sort(t_node **stack_a, t_node **stack_b, int size)
{
	int	bits;
	int	i;

	i = 0;
	bits = bits_calculator(size);
	while (i < bits)
	{
		ft_sort_binary(stack_a, stack_b, i, size);
		while ((*stack_b))
		{
			push_a(stack_b, stack_a);
		}
		i++;
	}
}
