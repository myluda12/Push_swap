/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajrhou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 17:45:18 by ayajrhou          #+#    #+#             */
/*   Updated: 2021/09/28 17:45:20 by ayajrhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit(char *str)
{
	ft_putstr(str);
	exit(0);
}

void	ft_duplicate_error(char **argv, int i)
{
	int	j;

	j = 1;
	while (j < i)
	{
		if (ft_atoi(argv[j]) == ft_atoi(argv[i]))
			ft_exit("Error");
		j++;
	}
}

void	ft_error_tratement(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		while (argv[i][j])
		{
			if (argv[i][j] == '-')
				j++;
			if (!ft_isdigit(argv[i][j]))
				ft_exit("Error");
			j++;
		}
		ft_duplicate_error(argv, i);
		j = 0;
		i++;
	}
}

void	ft_check_int(char **argv)
{
	int		i;
	int		j;
	char	*str;

	i = 1;
	while (argv[i])
	{
		if (*argv[i] == '0')
		{
			while (*argv[i] == '0')
				(argv[i])++;
		}
		j = ft_atoi(argv[i]);
		str = ft_itoa(j);
		if (strcmp(str, argv[i]) && j != 0)
			ft_exit("error");
		free(str);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		len;

	if (argc == 1)
		ft_exit("");
	ft_check_int(argv);
	stack_a = fillstack(argv, argc - 1);
	stack_b = NULL;
	len = argc - 1;
	ft_error_tratement(argv);
	bubblesort(stack_a, argc - 1);
	a_is_sorted(stack_a, 1);
	if (argc == 3)
		stack_a = rotate_a(stack_a);
	 else if (argc == 4)
		 stack_a = ft_3_num(stack_a, len);
	else if (argc == 5)
		stack_a = ft_4_num(stack_a, stack_b, 4);
	else if (argc == 6)
		stack_a = ft_4_num(stack_a, stack_b, 5);
	else
		ft_bit_sort(&stack_a, &stack_b, argc - 1);
}
