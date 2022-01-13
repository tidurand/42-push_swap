/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 08:23:50 by tidurand          #+#    #+#             */
/*   Updated: 2022/01/13 06:43:13 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*value_to_index(int *nb, int len)
{
	int	i;
	int	j;
	int	*index;

	index = malloc(sizeof(int) * (len) + 4);
	if (index == NULL)
	{
		free(nb);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < len)
	{
		index[i] = 1;
		j = 0;
		while (j < len)
		{
			if (nb[i] > nb[j] && nb[i] != nb[j])
				index[i]++;
			j++;
		}
		i++;
	}
	index[i] = '\0';
	return (index);
}

void	check_errors(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		if (av[i][0] == '-')
		{
			j++;
		}
		while (av[i][j])
		{
			if (!(av[i][j] >= '0' && av[i][j] <= '9'))
			{
				putstr("Error\n");
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
	check_doubles(av);
}

void	check_doubles(char **av)
{
	int	i;
	int	i2;

	i = 1;
	while (av[i])
	{
		i2 = i + 1;
		while (av[i2])
		{
			if (ft_strcmp(av[i], av[i2]) == 0)
			{
				putstr("Error\n");
				exit(EXIT_FAILURE);
			}
			i2++;
		}
		i++;
	}
}

void	check_errors_2(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		while (av[i] == ' ')
			i++;
		if (av[i] == '-')
			i++;
		if (!(av[i] >= '0' && av[i] <= '9'))
		{
			putstr("Error\n");
			exit(EXIT_FAILURE);
		}
		i++;
		while (av[i] == ' ')
			i++;
	}
}

void	check_doubles_2(int *nb)
{
	int	i;
	int	i2;

	i = 0;
	while (nb[i])
	{
		i2 = i + 1;
		while (nb[i2])
		{
			if (nb[i] - nb[i2] == 0)
			{
				putstr("Error\n");
				free(nb);
				exit(EXIT_FAILURE);
			}
			i2++;
		}
		i++;
	}
}
