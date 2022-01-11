/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 10:14:16 by tidurand          #+#    #+#             */
/*   Updated: 2022/01/11 12:37:18 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	main_push_swap(t_stack a_stack, int len)
{
	int		smaller;
	t_stack	b_stack;
	int		len2;
	int		len14;
	int		this_len;

	len2 = len / 2 + len % 2;
	len14 = len2 / 2 + len2 % 2;
	b_stack = create_b_stack(a_stack, len);
	smaller = presort(a_stack, b_stack, len2, len14);
	sort_and_empty_b(a_stack, b_stack, smaller, len14);
	last_good_n_last(a_stack);
	cut_18(a_stack, b_stack, &smaller, len);
	cut_1(a_stack, b_stack, &smaller, len14);
	this_len = cut_38(a_stack, b_stack, len);
	smaller = a_stack->end->value + 1;
	b_stack = push_b_section(a_stack, len2, smaller);
	smaller = a_stack->end->value + 1;
	this_len = list_len(b_stack);
	sort_and_empty_b(a_stack, b_stack, smaller, len2);
	last_good_n_last(a_stack);
	this_len = cut_58(a_stack, b_stack, len, &this_len);
	end_loop(a_stack, this_len, len);
}

void	all_cases(int ac, t_stack a_stack)
{
	t_stack	b_stack;
	int		len;

	len = ac - 1;
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
		main_push_swap(a_stack, len);
}

int	*parsing_1(char **av, int ac)
{
	int	i;
	int	*nb;

	i = 1;
	check_errors(av);
	nb = malloc(sizeof(int) * (ac));
	if (nb == NULL)
		exit(EXIT_FAILURE);
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
	int	*nb;
	int	i;

	i = 0;
	check_errors_2(av[1]);
	nb = malloc(sizeof(int) * (ft_strlen(av[1])));
	if (nb == NULL)
		exit(EXIT_FAILURE);
	while (av[1][i])
	{
		nb[i] = ft_atoi(av[1]);
		av[1] = ft_new_av(av[1]);
		i++;
		if (only_spaces(av[1]) == 1)
			break ;
	}
	nb[i] = '\0';
	*ac = i + 1;
	check_doubles_2(nb);
	return (nb);
}

int	main(int ac, char **av)
{
	t_stack	a_stack;
	int		i;
	int		*nb;
	int		*index;

	i = 0;
	a_stack = NULL;
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
