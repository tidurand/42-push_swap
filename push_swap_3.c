/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 09:05:53 by tidurand          #+#    #+#             */
/*   Updated: 2022/01/11 12:06:15 by tidurand         ###   ########.fr       */
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
