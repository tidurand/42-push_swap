/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 13:39:40 by tidurand          #+#    #+#             */
/*   Updated: 2022/01/10 13:54:11 by tidurand         ###   ########.fr       */
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
