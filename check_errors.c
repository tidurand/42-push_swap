/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 08:23:50 by tidurand          #+#    #+#             */
/*   Updated: 2022/01/06 06:59:44 by tidurand         ###   ########.fr       */
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

/*char	**new_av(char *av)
{
	char **str;

	str = ft_split(av, ' ');
	return (str);
}*/