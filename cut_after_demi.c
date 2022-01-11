/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 07:36:24 by tidurand          #+#    #+#             */
/*   Updated: 2022/01/11 07:42:01 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	end_loop(t_stack a_stack, int this_len, int len)
{
	int mark;
	t_stack b_stack;
	int len34;

	b_stack = NULL;
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