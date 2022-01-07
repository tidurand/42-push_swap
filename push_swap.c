/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 10:14:16 by tidurand          #+#    #+#             */
/*   Updated: 2022/01/07 09:03:42 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

Stack create_B_Stack(Stack A_Stack, int len)
{
	Stack B_Stack = NULL;
	int mark;
	
	mark = len / 2 + len % 2;
	while (len > 0)
	{
		if (A_Stack->begin->value <= mark)
		{
			B_Stack = push_front(B_Stack, A_Stack->begin->value);
			pop_front(A_Stack);
			putstr("pb\n");
		}
		else
		{
			rotate(A_Stack);
			putstr("ra\n");
		}
		len--;
	}
	return (B_Stack);
}

int step_2(Stack A_Stack, Stack B_Stack, int len)
{
	int mark;
	int smaller;

	mark = len / 2 + len % 2;
	smaller = 1;
	printf("MARK2 : %d\n", mark);
	while (len > 0)
	{
		if (B_Stack->begin->value >= mark)
		{
			A_Stack = push_front(A_Stack, B_Stack->begin->value);
			pop_front(B_Stack);
			putstr("pa\n");
		}
		else if (B_Stack->begin->value == smaller)
		{
			A_Stack = push_front(A_Stack, B_Stack->begin->value);
			pop_front(B_Stack);
			rotate(A_Stack);
			putstr("pa\nra\n");
			smaller++;
		}
		else
		{
			rotate(B_Stack);
			putstr("rb\n");
		}
		len--;
	}
	return (smaller);
}

void step_3(Stack A_Stack, Stack B_Stack, int smaller, int len)
{
	int higher;
	
	higher = len / 2 + len % 2;
	higher--;
	while (B_Stack->begin->next)
	{
		if (B_Stack->begin->value == higher)
		{
			A_Stack = push_front(A_Stack, B_Stack->begin->value);
			pop_front(B_Stack);
			putstr("pa\n");
			higher--;
		}
		else if (B_Stack->begin->value == smaller)
		{
			A_Stack = push_front(A_Stack, B_Stack->begin->value);
			pop_front(B_Stack);
			rotate(A_Stack);
			putstr("pa\nra\n");
			smaller++;
		}
		else
		{
			rotate(B_Stack);
			putstr("rb\n");
		}
	}
	A_Stack = push_front(A_Stack, B_Stack->begin->value);
	rotate(A_Stack);
	pop_back(B_Stack);
	putstr("pa\nra\n");
}

void	step_4(Stack A_Stack, int len)
{
	int mark;
	
	mark = len / 2 + len % 2;
	while (A_Stack->end->value != mark - 1)
	{
		rotate(A_Stack);
		putstr("ra\n");
	}
} 

Stack step_5(Stack A_Stack, int mark, int small)
{
	Stack	B_Stack = NULL;
	
	while (A_Stack->begin->value <= mark)
	{
		if (A_Stack->begin->value == small)
		{
			rotate(A_Stack);
			putstr("ra\n");
			small++;
		}
		else
		{
			B_Stack = push_front(B_Stack, A_Stack->begin->value);
			pop_front(A_Stack);
			putstr("pb\n");
		}
	}
	return (B_Stack);
}

void step_6(Stack A_Stack, Stack B_Stack, int small, int high)
{
	while (B_Stack->begin->next)
	{
		if (B_Stack->begin->value == high)
		{
			A_Stack = push_front(A_Stack, B_Stack->begin->value);
			pop_front(B_Stack);
			putstr("pa\n");
			high--;
		}
		else if (B_Stack->begin->value == small)
		{
			A_Stack = push_front(A_Stack, B_Stack->begin->value);
			pop_front(B_Stack);
			rotate(A_Stack);
			putstr("pa\nra\n");
			small++;
		}
		else
		{
			rotate(B_Stack);
			putstr("rb\n");
		}
	}
	A_Stack = push_front(A_Stack, B_Stack->begin->value);
	rotate(A_Stack);
	pop_back(B_Stack);
	putstr("pa\nra\n");
}

Stack step_7(Stack A_Stack, int len)
{
	Stack B_Stack = NULL;
	int mark;

	mark = (len / 2 + len % 2);
	mark = mark + (mark / 2 + mark % 2);
	printf("MARK : %d\n", mark);
	while (A_Stack->begin->value >= (len / 2 + len % 2))
	{
		if (A_Stack->begin->value >= mark)
		{
			rotate(A_Stack);
			putstr("ra\n");
		}
		else
		{
			B_Stack = push_front(B_Stack, A_Stack->begin->value);
			pop_front(A_Stack);
			putstr("pb\n");
		}
	}
	return (B_Stack);
}

/*void	step_8(Stack A_Stack, Stack B_Stack)
{
	
}*/

int	*value_to_index(int *nb, int len)
{
	int i;
	int j;
	int *index;

	index = malloc(sizeof(int) * (len) + 4);
	i = 0;
	while (i < len)
	{
		index[i] = 1;
		j = 0;
		while (j < len)
		{
			if (nb[i] > nb[j] && nb[i] != nb[j])
			{
				index[i]++;
			}
			j++;
		}
		i++;
	}
	index[i] = '\0';
	return(index);
}

int main(int ac, char **av)
{
	int		i = 1;
	int		*nb;
	Stack	A_Stack = NULL;
	Stack	B_Stack = NULL;
	int len;
	int *index;
	int smaller = 0;
	int higher;

	check_errors(av);
	if (ac <= 1)
		return (0);
	/*if (ac == 2)
	{
		av = string_case(av[1]);
		i = 0;
	}*/
	nb = malloc(sizeof(int) * (ac));
	while (av[i])
	{
		nb[i-1] = ft_atoi(av[i]);
		i++;
	}
	nb[i-1] = '\0';
	len = ac - 1;
	index = value_to_index(nb, len);
	free(nb);
	i = 0;
	while (index[i])
	{
		A_Stack = push_back(A_Stack, index[i]);
		i++;
	}
	free (index);
	/*if (ac == 3)
		push_swap_2(A_Stack);
	if (ac == 4)
		push_swap_3(A_Stack);*/
	if (ac > 4)
	{
		B_Stack = create_B_Stack(A_Stack, len);
		smaller = step_2(A_Stack, B_Stack, (len / 2 + len % 2));
		step_3(A_Stack, B_Stack, smaller, (len / 2 + len % 2));
		//B_Stack = NULL;
		step_4(A_Stack, (len / 2 + len % 2));
		smaller = A_Stack->end->value + 1;
		B_Stack = step_5(A_Stack, (len / 2 + len % 2), smaller);
		smaller = A_Stack->end->value + 1;
		higher = (len / 2 + len % 2);
		step_6(A_Stack, B_Stack, smaller, higher);
		step_4(A_Stack, len + 1);
		/*moitie triee, fin en boucle*/
		B_Stack = step_7(A_Stack, len);
		//step_8(A_Stack, B_Stack);
		print_list(A_Stack);
		print_list(B_Stack);
	}
	//print_list(A_Stack);
	while (!is_empty_list(A_Stack))
		A_Stack = pop_back(A_Stack);
	/*while (!is_empty_list(B_Stack))
		B_Stack = pop_back(B_Stack); //remove at the end*/
	return (0);
}
