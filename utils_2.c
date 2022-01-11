/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 10:53:38 by tidurand          #+#    #+#             */
/*   Updated: 2022/01/11 12:57:18 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack a_stack, t_stack b_stack)
{
	a_stack = push_front(a_stack, b_stack->begin->value);
	pop_front(b_stack);
	putstr("pa\n");
}

int	only_spaces(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (av[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

char	*ft_new_av(char *av)
{
	int	i;

	i = 0;
	while (av[i] == ' ')
		i++;
	while (av[i] != ' ' && av[i])
	{
		av[i] = ' ';
		i++;
	}
	return (av);
}

int	alone(char **av)
{
	int	i;

	i = 0;
	ft_atoi(av[1]);
	if (av[2])
		return (1);
	while (av[1][i])
	{
		if (av[1][i] == ' ')
			return (1);
		if (av[1][0] == '-')
			i++;
		if (!(av[1][i] >= '0' && av[1][i] <= '9'))
		{
			putstr("Error\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return (0);
}

int	already_sort(t_stack a_stack)
{
	t_node	*temp;

	temp = a_stack->begin;
	if (a_stack->begin->value != 1)
		return (0);
	while (temp->next)
	{
		if (temp->value != temp->next->value - 1)
			return (0);
		temp = temp->next;
	}
	return (1);
}
