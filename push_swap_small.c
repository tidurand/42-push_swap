/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_small.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 13:39:40 by tidurand          #+#    #+#             */
/*   Updated: 2022/01/10 16:05:11 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_pos(t_stack a_stack, t_stack b_stack, int *small, int *high)
{
	if (b_stack->begin->value == *high)
	{
		a_stack = push_front(a_stack, b_stack->begin->value);
		pop_front(b_stack);
		putstr("pa\n");
		(*high)--;
	}
	else if (b_stack->begin->value == *small)
	{
		a_stack = push_front(a_stack, b_stack->begin->value);
		pop_front(b_stack);
		(*small)++;
		putstr("pa\n");
		rotate(a_stack);
		if (b_stack->begin->value != *small && b_stack->begin->value != *high)
		{
			rotate(b_stack);
			putstr("rr\n");
		}
		else
			putstr("ra\n");
	}
	else
	{
		rotate(b_stack);
		putstr("rb\n");
	}
}

void	cut_1(t_stack a_stack, t_stack b_stack, int *small, int len)
{
	b_stack = push_b_section(a_stack, len, *small);
	*small = a_stack->end->value + 1;
	sort_and_empty_b(a_stack, b_stack, *small, len);
	last_good_n_last(a_stack);
}

int	cut_2(t_stack a_stack, t_stack b_stack, int mark, int len)
{
	int	this_len;

	b_stack = push_b_non_sort(a_stack, len);
	this_len = list_len(b_stack);
	bad_n_up(a_stack, b_stack, mark, len);
	sort_and_empty_b(a_stack, b_stack, mark + 1, b_stack->begin->value);
	last_good_n_last(a_stack);
	return (this_len);
}

//fct make good len
