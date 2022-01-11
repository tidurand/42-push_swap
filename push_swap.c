/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 10:14:16 by tidurand          #+#    #+#             */
/*   Updated: 2022/01/11 09:01:50 by tidurand         ###   ########.fr       */
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

int	only_spaces(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (av[i] != ' ')
		{
			return (0);
		}
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
	if (av[2])
		return (1);
	while (av[1][i])
	{
		if (av[1][i] == ' ')
			return (1);
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
		temp = temp-> next;
	}
	return (1);
}

void	all_cases(int ac, t_stack a_stack)
{
	int smaller = 0;
	t_stack	b_stack = NULL;
	int len;
	
	len = ac - 1;
	int len2 = len / 2 + len % 2;
	int len14 = len2 / 2 + len2 % 2;
	int this_len;
	if (already_sort(a_stack) == 1)
		ac = 0;
	if (ac == 3)
		push_swap_2(a_stack);
	if (ac == 4)
		push_swap_3(a_stack);
	if (ac == 5)
		push_swap_4(a_stack);
	if (ac == 6)
		push_swap_5(a_stack);
	if (ac <= 70 && ac > 6)
	{
		b_stack = push_all_except_one(a_stack);
		sort_and_empty_b(a_stack, b_stack, 2, len);
		last_good_n_last(a_stack);
	}
	if (ac > 70)
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
			cut_1(a_stack, b_stack, &smaller, len18);
		}
		//cut 1/4
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
		//cut en boucle a partir de 3/4
		end_loop(a_stack, this_len, len);
	}
}

int	*parsing_1(char **av, int ac)
{
	int i;
	int *nb;

	i = 1;
	check_errors(av);
	nb = malloc(sizeof(int) * (ac));
	while (av[i])
	{
		nb[i - 1] = ft_atoi(av[i]);
		i++;
	}
	nb[i - 1] = '\0';
	return (nb);
}

int	*parsing_2(char **av, int *ac)
{
	int *nb;
	int i;

	i = 0;
	check_errors_2(av[1]);
	nb = malloc(sizeof(int) * (ft_strlen(av[1])));
	while (av[1][i])
	{
		nb[i] = ft_atoi(av[1]);
		av[1] = ft_new_av(av[1]);
		i++;
		if (only_spaces(av[1]) == 1)
			break;
	}
	nb[i] = '\0';
	*ac = i + 1;
	check_doubles_2(nb);
	return (nb);
}

int main(int ac, char **av)
{
	t_stack	a_stack = NULL;
	int		i;
	int		*nb;
	int		*index;

	i = 0;
	if (ac <= 1 || alone(av) == 0)
		return (0);
	if (ac > 2)
		nb = parsing_1(av, ac);
	if (ac == 2)
		nb = parsing_2(av, &ac);
	index = value_to_index(nb, ac - 1);
	free(nb);
	while (index[i])
	{
		a_stack = push_back(a_stack, index[i]);
		i++;
	}
	free(index);
	all_cases(ac, a_stack);
	while (!is_empty_list(a_stack))
		a_stack = pop_back(a_stack);
	return (0);
}

//-8 doesnt work
//PROTEGER LES MALLOC