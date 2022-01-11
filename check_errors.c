/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 08:23:50 by tidurand          #+#    #+#             */
/*   Updated: 2022/01/11 07:17:27 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
