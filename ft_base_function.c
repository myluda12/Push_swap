/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajrhou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 16:11:21 by ayajrhou          #+#    #+#             */
/*   Updated: 2021/09/28 16:11:22 by ayajrhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*swap_a(t_node *stack)
{
	int		value;

	ft_putstr("sa\n");
	value = stack->value;
	stack->value = stack->next->value;
	stack->next->value = value;
	return (stack);
}

t_node	*swap_b(t_node *stack)
{
	int		value;

	ft_putstr("sb\n");
	value = stack->value;
	stack->value = stack->next->value;
	stack->next->value = value;
	return (stack);
}

t_node	*rotate_reverse_a(t_node *stack)
{
	t_node	*foot;
	t_node	*head;
	t_node	*beforand;

	ft_putstr("rra\n");
	head = stack;
	beforand = stack;
	while (stack->next)
		stack = stack->next;
	while (beforand->next->next)
		beforand = beforand->next;
	foot = stack;
	foot->next = head;
	beforand->next = NULL;
	return (foot);
}

t_node	*rotate_a(t_node *stack)
{
	t_node	*tmp;
	t_node	*head;

	ft_putstr("ra\n");
	head = stack->next;
	tmp = stack;
	while (stack->next)
		stack = stack->next;
	stack->next = tmp;
	tmp->next = NULL;
	return (head);
}

t_node	*rotate_b(t_node *stack)
{
	t_node	*tmp;
	t_node	*head;

	ft_putstr("rb\n");
	head = stack->next;
	tmp = stack;
	while (stack->next)
		stack = stack->next;
	stack->next = tmp;
	tmp->next = NULL;
	return (head);
}
