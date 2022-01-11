/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 10:14:22 by tidurand          #+#    #+#             */
/*   Updated: 2022/01/11 07:13:30 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
}

int	ft_atoi(char *str)
{
	int		sign;
	long	nb;
	int		i;

	sign = 1;
	nb = 0;
	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign *= (-1);
	if (str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb *= 10;
		nb += (int)str[i] - '0';
		if ((nb > 2147483647 && sign == 1) || (nb > 2147483648 && sign == -1))
		{
			putstr("Error\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return (sign * nb);
}

int	list_len(t_stack A_Stack)
{
	int		len;
	t_node	*temp;

	temp = A_Stack->begin;
	len = 1;
	while (temp->next)
	{
		len++;
		temp = temp->next;
	}
	return (len);
}

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_intlen(int *tab)
{
	int	len;

	len = 0;
	while (tab[len])
	{
		len ++;
	}
	return (len);
}

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
	{
		len ++;
	}
	return (len);
}
