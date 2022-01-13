/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 08:41:03 by tidurand          #+#    #+#             */
/*   Updated: 2022/01/07 09:12:48 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	swap(t_stack Stack)
{
	int	temp;
	int	temp2;

	if (Stack->begin == Stack->end)
		return (Stack);
	temp = Stack->begin->value;
	temp2 = Stack->begin->next->value;
	push_front(Stack, temp);
	push_front(Stack, temp2);
	pop_back(Stack);
	pop_back(Stack);
	return (Stack);
}

t_stack	rotate(t_stack Stack)
{
	push_back(Stack, Stack->begin->value);
	pop_front(Stack);
	return (Stack);
}

t_stack	reverse_rotate(t_stack Stack)
{
	push_front(Stack, Stack->end->value);
	pop_back(Stack);
	return (Stack);
}
