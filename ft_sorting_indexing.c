/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting_indexing.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajrhou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 16:10:47 by ayajrhou          #+#    #+#             */
/*   Updated: 2021/09/28 16:10:52 by ayajrhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*bubblesort1(t_node *stack, int n)
{
	int		i;
	int		*tab;
	t_node	*tmp;
	t_node	*ret;

	ret = stack;
	i = 0;
	tmp = stack;
	tab = malloc(sizeof(int) * n);
	while (stack)
	{
		tab[i] = stack->value;
		stack = stack->next;
		i++;
	}
	return (tab);
}

t_node	*bubblesort2(int *tab, t_node *tmp, int n)
{
	int	i;

	i = 0;
	while (tmp)
	{
		i = -1;
		while (++i < n)
		{
			if (tmp->value == tab[i])
			{
				tmp->value = i;
				tmp = tmp->next;
				break ;
			}
		}
	}
	return (tmp);
}

t_node	*bubblesort(t_node *stack, int n)
{
	int		i;
	int		j;
	int		*tab;
	t_node	*tmp;
	t_node	*ret;

	ret = stack;
	tmp = stack;
	tab = bubblesort1(stack, n);
	i = 0;
	while (i < n - 1)
	{
		j = 0;
		while (j < n - i - 1)
		{
			if (tab[j] > tab[j + 1])
				ft_swap(&tab[j], &tab[j + 1]);
			j++;
		}
		i++;
	}
	tmp = bubblesort2(tab, tmp, n);
	free(tab);
	return (ret);
}

int	a_is_sorted(t_node *stack, int flag)
{
	while (stack->next && stack->value < stack->next->value)
	{
		stack = stack->next;
		if (stack->next == NULL && flag == 1)
		{
			if (!(flag == 0))
				exit(0);
			return (1);
		}
	}
	return (0);
}

t_node	*fillstack(char **array, int size)
{
	t_node	*stack;
	t_node	*tmp;
	int		i;

	i = 1;
	if (size < 0)
		return (NULL);
	stack = (t_node *)malloc(sizeof(t_node) * 1);
	tmp = stack;
	if (!stack)
		return (NULL);
	stack->value = atoi(array[i++]);
	stack->next = NULL;
	while (i <= size)
	{
		stack->next = (t_node *)malloc(sizeof(t_node) * 1);
		stack->next->value = atoi(array[i++]);
		stack->next->next = NULL;
		stack = stack->next;
	}
	return (tmp);
}
