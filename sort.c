/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:42:28 by tidurand          #+#    #+#             */
/*   Updated: 2022/01/10 15:23:58 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	presort(t_stack a_stack, t_stack b_stack, int len, int mark)
{
	int	smaller;
	int	len_b;
	int	temp;

	smaller = 1;
	temp = len;
	len_b = list_len(b_stack);
	while (len_b > 15)
	{
		while (len > 0)
		{
			if (b_stack->begin->value >= mark)
			{
				a_stack = push_front(a_stack, b_stack->begin->value);
				pop_front(b_stack);
				putstr("pa\n");
			}
			else if (b_stack->begin->value == smaller)
			{
				a_stack = push_front(a_stack, b_stack->begin->value);
				pop_front(b_stack);
				smaller++;
				putstr("pa\n");
				rotate(a_stack);
				if (b_stack->begin->value != smaller && b_stack->begin->value < mark)
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
			len--;
		}
		len_b = list_len(b_stack);
		len = len_b;
		mark = mark - (mark / 2 + mark % 2);
	}
	return (smaller);
}

void	last_good_n_last(t_stack a_stack)
{
	while (a_stack->end->value + 1 == a_stack->begin->value)
	{
		rotate(a_stack);
		putstr("ra\n");
	}
}

void	sort_and_empty_b(t_stack a_stack, t_stack b_stack, int small, int high)
{
	while (b_stack->begin->next)
	{
		three_pos(a_stack, b_stack, &small, &high);
	}
	a_stack = push_front(a_stack, b_stack->begin->value);
	rotate(a_stack);
	pop_back(b_stack);
	putstr("pa\nra\n");
}

void	bad_n_up(t_stack a_stack, t_stack b_stack, int mark, int len34)
{
	while (a_stack->end->value != mark)
	{
		reverse_rotate(a_stack);
		if (b_stack->begin->value != len34 -1)
		{
			reverse_rotate(b_stack);
			putstr("rrr\n");
		}
		else
			putstr("rra\n");
	}
}
