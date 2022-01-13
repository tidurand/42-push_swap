/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 06:00:48 by tidurand          #+#    #+#             */
/*   Updated: 2022/01/11 15:35:26 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_empty_list(t_stack Stack)
{
	if (Stack == NULL)
		return (1);
	return (0);
}

t_stack	push_back(t_stack Stack, int x)
{
	t_node	*element;

	element = malloc(sizeof(*element));
	if (element == NULL)
		return (NULL);
	element->value = x;
	element->next = NULL;
	element->back = NULL;
	if (is_empty_list(Stack))
	{
		Stack = malloc(sizeof(*Stack));
		if (Stack == NULL)
			return (NULL);
		Stack->begin = element;
		Stack->end = element;
	}
	else
	{
		Stack->end->next = element;
		element->back = Stack->end;
		Stack->end = element;
	}
	return (Stack);
}

t_stack	push_front(t_stack Stack, int x)
{
	t_node	*element;

	element = malloc(sizeof(*element));
	if (element == NULL)
		return (NULL);
	element->value = x;
	element->next = NULL;
	element->back = NULL;
	if (is_empty_list(Stack))
	{
		Stack = malloc(sizeof(*Stack));
		if (Stack == NULL)
			return (NULL);
		Stack->begin = element;
		Stack->end = element;
	}
	else
	{
		Stack->begin->back = element;
		element->next = Stack->begin;
		Stack->begin = element;
	}
	return (Stack);
}

t_stack	pop_back(t_stack Stack)
{
	t_node	*temp;

	temp = Stack->end;
	if (Stack->begin == Stack->end)
	{
		free(Stack);
		return (NULL);
	}
	Stack->end = temp->back;
	Stack->end->next = NULL;
	free(temp);
	return (Stack);
}

t_stack	pop_front(t_stack Stack)
{
	t_node	*temp;

	if (Stack->begin == Stack->end)
	{
		free(Stack);
		return (NULL);
	}
	temp = Stack->begin;
	Stack->begin = temp->next;
	Stack->begin->back = NULL;
	free(temp);
	return (Stack);
}
