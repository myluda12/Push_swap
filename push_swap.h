/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajrhou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 17:55:47 by ayajrhou          #+#    #+#             */
/*   Updated: 2021/09/28 17:55:48 by ayajrhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

typedef struct t_node
{
	int				value;
	struct t_node	*next;
}				t_node;

int		ft_atoi(const char *str);
void	ft_duplicate_error(char **argv, int i);
char	*ft_itoa(int n);
int		ft_long_atoi(const char *str);
int		*bubblesort1(t_node *stack, int n);
t_node	*bubblesort2(int *tab, t_node *tmp, int n);
t_node	*bubblesort(t_node *stack, int n);
int		a_is_sorted(t_node *stack, int flag);
t_node	*fillstack(char **array, int size);
int		main(int argc, char **argv);
void	ft_check_int(char **argv);
void	ft_error_tratement(char **argv);
void	ft_exit(char *str);
t_node	*ft_3_num(t_node *stack_a, int fr);
t_node	*ft_5_num(t_node *stack_a, t_node *stack_b);
t_node	*ft_4_num(t_node *stack_a, t_node *stack_b, int i);
t_node	*ft_comparing_stack(t_node *stack_a, t_node *stack_b);
void	push_b(t_node **stack_b, t_node **stack_a);
void	push_a(t_node **stack_b, t_node **stack_a);
int		bits_calculator(int size);
void	ft_sort_binary(t_node **stack_a, t_node **stack_b, int i, int size);
void	ft_bit_sort(t_node **stack_a, t_node **stack_b, int size);
int		ft_strcmp(char *s1, char *s2);
int		ft_isdigit(int c);
void	ft_putstr(char *str);
void	ft_swap(int *xp, int *yp);
t_node	*swap_a(t_node *stack);
t_node	*swap_b(t_node *stack);
t_node	*rotate_reverse_a(t_node *stack);
t_node	*rotate_a(t_node *stack);
t_node	*rotate_b(t_node *stack);
void	ft_check_stackb(t_node **stack_a, t_node **stack_b, int c);
#endif
