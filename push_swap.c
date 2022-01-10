/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 10:14:16 by tidurand          #+#    #+#             */
/*   Updated: 2022/01/10 16:02:57 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*value_to_index(int *nb, int len)
{
	int	i;
	int	j;
	int	*index;

	index = malloc(sizeof(int) * (len) + 4);
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

int main(int ac, char **av)
{
	int		i = 1;
	int		*nb;
	t_stack	a_stack = NULL;
	t_stack	b_stack = NULL;
	int		len;
	int *index;
	int smaller = 0;

	check_errors(av);
	if (ac <= 1)
		return (0);
	nb = malloc(sizeof(int) * (ac));
	/*while (av[2])
	{
		 mettre dans un tableau de char[nb chiffres int max] en boucle 
	}*/

	while (av[i])
	{
		nb[i - 1] = ft_atoi(av[i]);
		i++;
	}
	nb[i - 1] = '\0';
	len = ac - 1;
	int len2 = len / 2 + len % 2;
	int len14 = len2 / 2 + len2 % 2;
	int len34 = 3 * (len / 4) + len % 4;
	int this_len;
	index = value_to_index(nb, len);
	free(nb);
	i = 0;
	while (index[i])
	{
		a_stack = push_back(a_stack, index[i]);
		i++;
	}
	free (index);
	if (ac == 3)
		push_swap_2(a_stack);
	if (ac == 4)
		push_swap_3(a_stack);
	if (ac > 4)
	{
		//pretri
		b_stack = create_b_stack(a_stack, len);
		smaller = presort(a_stack, b_stack, len2, len14);
		sort_and_empty_b(a_stack, b_stack, smaller, len14);
		last_good_n_last(a_stack);
		//cut 1/8
		if (len > 200)
		{
			int len18 = (len) / 8;
			if (len % 8 != 0)
				len18++;
			smaller = a_stack->end->value + 1;
			cut_1(a_stack, b_stack, &smaller, len18);
		}
		//cut 1/4
		smaller = a_stack->end->value + 1;
		cut_1(a_stack, b_stack, &smaller, len14);
		//cut 3/8
		int mark;
		if (len > 200)
		{
			int len38 = (3*len) / 8;
			if (len % 8 != 0)
				len38++;
			mark = a_stack->end->value;
			this_len = cut_2(a_stack, b_stack, mark, len38);
		}
		//cut 1/2
		smaller = a_stack->end->value + 1;
		b_stack = push_b_section(a_stack, len2, smaller);
		smaller = a_stack->end->value + 1;
		this_len = list_len(b_stack);
		sort_and_empty_b(a_stack, b_stack, smaller, len2);
		last_good_n_last(a_stack);
		//cut 5/8
		if (len > 200)
		{
			int len58 = (5*len) / 8;
			if (len % 8 != 0)
				len58++;
			mark = a_stack->end->value;
			this_len = cut_2(a_stack, b_stack, mark, len58);
		}
		//cut en boucle a partie de 3/4
		mark = a_stack->end->value;
		int i = 1;
		int j = 2;
		while (1)
		{
			if (this_len < 15)
			{
				b_stack = push_rest(a_stack);
				sort_and_empty_b(a_stack, b_stack, a_stack->end->value + 1, len);
				last_good_n_last(a_stack);
				break ;
			}
			else
			{
				i = i + j;
				j = j * 2;
				len34 = (i * len) / j;
				if (len % j != 0)
					len34++;
				mark = a_stack->end->value;
				this_len = cut_2(a_stack, b_stack, mark, len34);
			}
		}
	}
	while (!is_empty_list(a_stack))
		a_stack = pop_back(a_stack);
	return (0);
}

//-8 doesnt work