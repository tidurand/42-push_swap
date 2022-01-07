/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 10:14:22 by tidurand          #+#    #+#             */
/*   Updated: 2022/01/06 09:23:32 by tidurand         ###   ########.fr       */
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
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= (-1);
		i++;
	}
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

int	list_len(Stack A_Stack)
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


/*int	*ft_intdup(int *tab)
{
	int	*dest;
	int	i;

	i = 0;
	dest = malloc(sizeof(int) * (ft_intlen(tab) + 1));
	if (dest == NULL)
		return (NULL);
	while (tab[i])
	{
		dest[i] = tab[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}*/