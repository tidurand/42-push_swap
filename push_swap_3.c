/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 09:05:53 by tidurand          #+#    #+#             */
/*   Updated: 2022/01/11 05:07:44 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_2(t_stack Stack)
{
	if (Stack->begin->value > Stack->begin->next->value)
	{
		swap(Stack);
		putstr("sa\n");
	}
}

void	push_swap_3(t_stack Stack)
{
	if (Stack->begin->value > Stack->begin->next->value
		&& Stack->begin->value < Stack->begin->next->next->value)
	{
		swap(Stack);
		putstr("sa\n");
	}
	else if (Stack->begin->value > Stack->begin->next->value
		&& Stack->begin->next->value > Stack->begin->next->next->value)
	{
		swap(Stack);
		reverse_rotate(Stack);
		putstr("sa\nrra\n");
	}
	else
		push_swap_3_next(Stack);
}

void	push_swap_3_next(t_stack Stack)
{
	if (Stack->begin->value > Stack->begin->next->value
		&& Stack->begin->next->value < Stack->begin->next->next->value)
	{
		rotate(Stack);
		putstr("ra\n");
	}
	else if (Stack->begin->value < Stack->begin->next->value
		&& Stack->begin->value > Stack->begin->next->next->value)
	{
		reverse_rotate(Stack);
		putstr("rra\n");
	}
	else if (Stack->begin->value < Stack->begin->next->value
		&& Stack->begin->next->value > Stack->begin->next->next->value)
	{
		reverse_rotate(Stack);
		swap(Stack);
		putstr("rra\nsa\n");
	}
}

void	push_swap_4(t_stack a_stack)
{
	t_stack b_stack;
	
	b_stack = NULL;
	b_stack = push_front(b_stack, a_stack->begin->value);
	pop_front(a_stack);
	putstr("pb\n");
	push_swap_3(a_stack);
	if (b_stack->begin->value == 1)
	{
		a_stack = push_front(a_stack, b_stack->begin->value);
		pop_back(b_stack);
		putstr("pa\n");
	}
	else if (b_stack->begin->value == 2)
	{
		rotate(a_stack);
		a_stack = push_front(a_stack, b_stack->begin->value);
		pop_back(b_stack);
		reverse_rotate(a_stack);
		putstr("ra\npa\nrra\n");
	}
	else if (b_stack->begin->value == 3)
	{
		reverse_rotate(a_stack);
		a_stack = push_front(a_stack, b_stack->begin->value);
		pop_back(b_stack);
		rotate(a_stack);
		rotate(a_stack);
		putstr("rra\npa\nra\nra\n");
	}
	else if (b_stack->begin->value == 4)
	{
		a_stack = push_front(a_stack, b_stack->begin->value);
		pop_back(b_stack);
		rotate(a_stack);
		putstr("pa\nra\n");
	}
}

void	push_swap_5(t_stack a_stack)
{
	t_stack b_stack;
	int small;
	
	b_stack = NULL;
	small = 1;
	b_stack = push_front(b_stack, 0);
	while (b_stack->begin->value != 2)
	{
		if (a_stack->begin->value == small)
		{
			b_stack = push_front(b_stack, a_stack->begin->value);
			pop_front(a_stack);
			putstr("pb\n");
			small++;
		}
		else
		{
			rotate(a_stack);
			putstr("ra\n");
		}
	}
	push_swap_3(a_stack);
	a_stack = push_front(a_stack, b_stack->begin->value);
	pop_front(b_stack);
	a_stack = push_front(a_stack, b_stack->begin->value);
	pop_front(b_stack);
	pop_back(b_stack);
	putstr("pa\npa\n");
}