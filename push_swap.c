/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 10:14:16 by tidurand          #+#    #+#             */
/*   Updated: 2022/01/09 11:50:52 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack create_B_Stack(t_stack A_Stack, int len)
{
	t_stack	B_Stack = NULL;
	int		mark;

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

int step_2(t_stack A_Stack, t_stack B_Stack, int len, int mark)
{
	int	smaller;

	smaller = 1;
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

void step_3(t_stack A_Stack, t_stack B_Stack, int smaller, int higher)
{
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

void	first_number_first(t_stack A_Stack)
{
	while (A_Stack->end->value + 1 == A_Stack->begin->value)
	{
		rotate(A_Stack);
		putstr("ra\n");
	}
}

t_stack	step_5(t_stack A_Stack, int mark, int small)
{
	t_stack	B_Stack = NULL;

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

void sort_and_empty_B(t_stack A_Stack, t_stack B_Stack, int small, int high)
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

t_stack step_7(t_stack A_Stack, int len34)
{
	t_stack	B_Stack;

	B_Stack = NULL;
	while (A_Stack->begin->value != 1)
	{
		if (A_Stack->begin->value >= len34)
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

void	step_8(t_stack A_Stack, t_stack B_Stack, int mark, int len34)
{
	while (A_Stack->end->value != mark)
	{
		reverse_rotate(A_Stack);
		if (B_Stack->begin->value != len34 -1)
		{
			reverse_rotate(B_Stack);
			putstr("rrr\n");
		}
		else
		{
			putstr("rra\n");
		}
	}
}

t_stack push_rest(t_stack A_Stack)
{
	t_stack	B_Stack;

	B_Stack = NULL;
	while (A_Stack->begin->value != 1)
	{
		B_Stack = push_front(B_Stack, A_Stack->begin->value);
		pop_front(A_Stack);
		putstr("pb\n");
	}
	return (B_Stack);
}

int	*value_to_index(int *nb, int len)
{
	int	i;
	int	j;
	int	*index;

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
	return (index);
}

int main(int ac, char **av)
{
	int		i = 1;
	int		*nb;
	t_stack	A_Stack = NULL;
	t_stack	B_Stack = NULL;
	int len;
	int *index;
	int smaller = 0;

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
		nb[i - 1] = ft_atoi(av[i]);
		i++;
	}
	nb[i - 1] = '\0';
	len = ac - 1;
	int len2 = len / 2 + len % 2;
	int len14 = len2 / 2 + len2 % 2;
	int len34 = 3*(len/4) + len % 4;
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
		smaller = step_2(A_Stack, B_Stack, len2, len14);
		step_3(A_Stack, B_Stack, smaller, len14);
		B_Stack = NULL;
		first_number_first(A_Stack);
		smaller = A_Stack->end->value + 1;
		B_Stack = step_5(A_Stack, len2, smaller);
		smaller = A_Stack->end->value + 1;
		sort_and_empty_B(A_Stack, B_Stack, smaller, len2);
		first_number_first(A_Stack);
		int mark;
		mark = A_Stack->end->value;
		//moitie triee, fin en boucle
		int this_len;
		B_Stack = step_7(A_Stack, len34);
		this_len = list_len(B_Stack);
		step_8(A_Stack, B_Stack, mark, len34);
		sort_and_empty_B(A_Stack, B_Stack, mark + 1, B_Stack->begin->value);
		first_number_first(A_Stack);
		// 3/4 trie
		//B_Stack = step_7(A_Stack, len + len2);
		//step_8(A_Stack, B_Stack, len + len34);
		//print_list(A_Stack);
		//print_list(B_Stack);
		//end
		int i = 3;
		int j = 4;
		while (1)
		{
			if (this_len < 15)
			{
				B_Stack = push_rest(A_Stack);
				sort_and_empty_B(A_Stack, B_Stack,A_Stack->end->value + 1, len);
				first_number_first(A_Stack);
				break ;
			}
			else
			{
				i = i+j;
				j = j*2;
				len34 = (i*len) / j;
				if (len % j != 0)
					len34++;
				mark = A_Stack->end->value;
				B_Stack = step_7(A_Stack, len34);
				this_len = list_len(B_Stack);
				step_8(A_Stack, B_Stack, mark, len34);
				sort_and_empty_B(A_Stack, B_Stack, mark + 1, B_Stack->begin->value);
				first_number_first(A_Stack);
			}
		}
		// if -15, if -200, if +200;
	}
	//print_list(A_Stack);
	while (!is_empty_list(A_Stack))
		A_Stack = pop_back(A_Stack);
	return (0);
}
