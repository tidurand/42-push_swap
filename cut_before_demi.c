/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_before_demi.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 08:43:03 by tidurand          #+#    #+#             */
/*   Updated: 2022/01/11 11:18:35 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cut_18(t_stack a_stack, t_stack b_stack, int *small, int len)
{
	int	len18;

	if (len > 200)
	{
		len18 = (len) / 8;
		if (len % 8 != 0)
			len18++;
		cut_1(a_stack, b_stack, small, len18);
	}
}

int	cut_38(t_stack a_stack, t_stack b_stack, int len)
{
	int	len38;
	int	mark;
	int	this_len;

	if (len > 200)
	{
		len38 = (3 * len) / 8;
		if (len % 8 != 0)
			len38++;
		mark = a_stack->end->value;
		this_len = cut_2(a_stack, b_stack, mark, len38);
		return (this_len);
	}
	return (0);
}

int	cut_58(t_stack a_stack, t_stack b_stack, int len, int *this_len)
{
	int	len58;
	int	mark;

	if (len > 200)
	{
		len58 = (5 * len) / 8;
		if (len % 8 != 0)
			len58++;
		mark = a_stack->end->value;
		*this_len = cut_2(a_stack, b_stack, mark, len58);
	}
	return (*this_len);
}
