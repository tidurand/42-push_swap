/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 10:14:16 by tidurand          #+#    #+#             */
/*   Updated: 2022/01/10 14:06:42 by tidurand         ###   ########.fr       */
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

int	presort(t_stack a_stack, t_stack b_stack, int len, int mark)
{
	int	smaller;
	int	len_b;
	int	temp;

	smaller = 1;
	temp = len;
	len_b = list_len(b_stack);
	while (len_b > 15)
	{
		while (len > 0)
		{
			if (b_stack->begin->value >= mark)
			{
				a_stack = push_front(a_stack, b_stack->begin->value);
				pop_front(b_stack);
				putstr("pa\n");
			}
			else if (b_stack->begin->value == smaller)
			{
				a_stack = push_front(a_stack, b_stack->begin->value);
				pop_front(b_stack);
				smaller++;
				putstr("pa\n");
				rotate(a_stack);
				if (b_stack->begin->value != smaller && b_stack->begin->value < mark)
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
			len--;
		}
		len_b = list_len(b_stack);
		len = len_b;
		mark = mark - (mark / 2 + mark % 2);
	}
	return (smaller);
}

void	last_good_n_last(t_stack a_stack)
{
	while (a_stack->end->value + 1 == a_stack->begin->value)
	{
		rotate(a_stack);
		putstr("ra\n");
	}
}

t_stack	step_5(t_stack a_stack, int mark, int small)
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

void sort_and_empty_B(t_stack a_stack, t_stack b_stack, int small, int high)
{
	while (b_stack->begin->next)
	{
		three_pos(a_stack, b_stack, &small, &high);
	}
	a_stack = push_front(a_stack, b_stack->begin->value);
	rotate(a_stack);
	pop_back(b_stack);
	putstr("pa\nra\n");
}

t_stack step_7(t_stack a_stack, int len34)
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

void	bad_n_up(t_stack a_stack, t_stack b_stack, int mark, int len34)
{
	while (a_stack->end->value != mark)
	{
		reverse_rotate(a_stack);
		if (b_stack->begin->value != len34 -1)
		{
			reverse_rotate(b_stack);
			putstr("rrr\n");
		}
		else
			putstr("rra\n");
	}
}

t_stack push_rest(t_stack a_stack)
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
				index[i]++;
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
	t_stack	a_stack = NULL;
	t_stack	b_stack = NULL;
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
	/*while (av[2])
	{
		 mettre dans un tableau de char[nb chiffres int max] en boucle 
	}*/

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
	int this_len;
	index = value_to_index(nb, len);
	free(nb);
	i = 0;
	while (index[i])
	{
		a_stack = push_back(a_stack, index[i]);
		i++;
	}
	free (index);
	/*if (ac == 3)
		push_swap_2(a_stack);
	if (ac == 4)
		push_swap_3(a_stack);*/
	if (ac > 4)
	{
		//pretri
		b_stack = create_b_stack(a_stack, len);
		smaller = presort(a_stack, b_stack, len2, len14);
		sort_and_empty_B(a_stack, b_stack, smaller, len14);
		last_good_n_last(a_stack);
		//cut 1/8
		if (len > 200)
		{
			int len18 = (len) / 8;
			if (len % 8 != 0)
				len18++;
			smaller = a_stack->end->value + 1;
			b_stack = step_5(a_stack, len18, smaller);
			smaller = a_stack->end->value + 1;
			this_len = list_len(b_stack);
			sort_and_empty_B(a_stack, b_stack, smaller, len18);
			last_good_n_last(a_stack);
		}
		//cut 1/4
		smaller = a_stack->end->value + 1;
		b_stack = step_5(a_stack, len14, smaller);
		smaller = a_stack->end->value + 1;
		this_len = list_len(b_stack);
		sort_and_empty_B(a_stack, b_stack, smaller, len14);
		last_good_n_last(a_stack);
		//cut 3/8
		int mark;
		if (len > 200)
		{
			int len38 = (3*len) / 8;
			if (len % 8 != 0)
				len38++;
			mark = a_stack->end->value;
			b_stack = step_7(a_stack, len38);
			this_len = list_len(b_stack);
			bad_n_up(a_stack, b_stack, mark, len38);
			sort_and_empty_B(a_stack, b_stack, mark + 1, b_stack->begin->value);
			last_good_n_last(a_stack);
		}
		//cut 1/2
		smaller = a_stack->end->value + 1;
		b_stack = step_5(a_stack, len2, smaller);
		smaller = a_stack->end->value + 1;
		this_len = list_len(b_stack);
		sort_and_empty_B(a_stack, b_stack, smaller, len2);
		last_good_n_last(a_stack);
		//cut 5/8
		if (len > 200)
		{
			int len58 = (5*len) / 8;
			if (len % 8 != 0)
				len58++;
			mark = a_stack->end->value;
			b_stack = step_7(a_stack, len58);
			this_len = list_len(b_stack);
			bad_n_up(a_stack, b_stack, mark, len58);
			sort_and_empty_B(a_stack, b_stack, mark + 1, b_stack->begin->value);
			last_good_n_last(a_stack);
		}
		//pretri de la deuxieme partie
		//cut en boucle a partie de 3/4
		mark = a_stack->end->value;
		int i = 1;
		int j = 2;
		while (1)
		{
			if (this_len < 15)
			{
				b_stack = push_rest(a_stack);
				sort_and_empty_B(a_stack, b_stack, a_stack->end->value + 1, len);
				last_good_n_last(a_stack);
				break ;
			}
			else
			{
				i = i + j;
				j = j * 2;
				len34 = (i * len) / j;
				if (len % j != 0)
					len34++;
				mark = a_stack->end->value;
				b_stack = step_7(a_stack, len34);
				this_len = list_len(b_stack);
				bad_n_up(a_stack, b_stack, mark, len34);
				sort_and_empty_B(a_stack, b_stack, mark + 1, b_stack->begin->value);
				last_good_n_last(a_stack);
			}
		}
	}
	while (!is_empty_list(a_stack))
		a_stack = pop_back(a_stack);
	return (0);
}

//-8 doesnt work