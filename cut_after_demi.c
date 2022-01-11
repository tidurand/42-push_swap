/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_after_demi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 07:36:24 by tidurand          #+#    #+#             */
/*   Updated: 2022/01/11 11:54:04 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	end(t_stack a_stack, int len)
{
	t_stack	b_stack;

	b_stack = push_rest(a_stack);
	sort_and_empty_b(a_stack, b_stack, a_stack->end->value + 1, len);
	last_good_n_last(a_stack);
	return (b_stack);
}

void	end_loop(t_stack a_stack, int this_len, int len)
{
	t_stack	b_stack;
	int		len34;
	int		i;
	int		j;

	b_stack = NULL;
	i = 1;
	j = 2;
	while (1)
	{
		if (this_len < 15)
		{
			b_stack = end(a_stack, len);
			break ;
		}
		else
		{
			i = i + j;
			j = j * 2;
			len34 = (i * len) / j;
			if (len % j != 0)
				len34++;
			this_len = cut_2(a_stack, b_stack, a_stack->end->value, len34);
		}
	}
}
