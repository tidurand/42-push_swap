/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 08:41:03 by tidurand          #+#    #+#             */
/*   Updated: 2021/12/16 20:19:32 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

Stack	swap(Stack Stack)
{
	int	temp;
	int	temp2;

	if (Stack->begin == Stack->end)
		return (Stack);
	temp = Stack->begin->value;
	temp2 = Stack->begin->next->value;
	if (Stack->begin->next->next)
	{
		Stack->begin = Stack->begin->next->next;
		push_front(Stack, temp);
		push_front(Stack, temp2);
	}
	else
	{
		push_front(Stack, temp);
		push_front(Stack, temp2);
		pop_back(Stack);
		pop_back(Stack);
	}
	return (Stack);
}

Stack	rotate(Stack Stack)
{
	push_back(Stack, Stack->begin->value);
	pop_front(Stack);
	return (Stack);
}

Stack	reverse_rotate(Stack Stack)
{
	push_front(Stack, Stack->end->value);
	pop_back(Stack);
	return (Stack);
}
