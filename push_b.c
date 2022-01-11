/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:41:47 by tidurand          #+#    #+#             */
/*   Updated: 2022/01/11 07:19:28 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	create_b_stack(t_stack a_stack, int len)
{
	t_stack	b_stack;
	int		mark;

	b_stack = NULL;
	mark = len / 2 + len % 2;
	while (len > 0)
	{
		if (a_stack->begin->value <= mark)
		{
			b_stack = push_front(b_stack, a_stack->begin->value);
			pop_front(a_stack);
			putstr("pb\n");
		}
		else
		{
			rotate(a_stack);
			putstr("ra\n");
		}
		len--;
	}
	return (b_stack);
}

t_stack	push_b_non_sort(t_stack a_stack, int len34)
{
	t_stack	b_stack;

	b_stack = NULL;
	while (a_stack->begin->value != 1)
	{
		if (a_stack->begin->value >= len34)
		{
			rotate(a_stack);
			putstr("ra\n");
		}
		else
		{
			b_stack = push_front(b_stack, a_stack->begin->value);
			pop_front(a_stack);
			putstr("pb\n");
		}
	}
	return (b_stack);
}

t_stack	push_rest(t_stack a_stack)
{
	t_stack	b_stack;

	b_stack = NULL;
	while (a_stack->begin->value != 1)
	{
		b_stack = push_front(b_stack, a_stack->begin->value);
		pop_front(a_stack);
		putstr("pb\n");
	}
	return (b_stack);
}

t_stack	push_b_section(t_stack a_stack, int mark, int small)
{
	t_stack	b_stack;

	b_stack = NULL;
	while (a_stack->begin->value <= mark)
	{
		if (a_stack->begin->value == small)
		{
			rotate(a_stack);
			putstr("ra\n");
			small++;
		}
		else
		{
			b_stack = push_front(b_stack, a_stack->begin->value);
			pop_front(a_stack);
			putstr("pb\n");
		}
	}
	return (b_stack);
}

t_stack	push_all_except_one(t_stack a_stack)
{
	t_stack	b_stack;

	b_stack = NULL;
	while (a_stack->begin->next)
	{
		if (a_stack->begin->value != 1)
		{
			b_stack = push_front(b_stack, a_stack->begin->value);
			pop_front(a_stack);
			putstr("pb\n");
		}
		else
		{
			rotate(a_stack);
			putstr("ra\n");
		}
	}
	return (b_stack);
}
