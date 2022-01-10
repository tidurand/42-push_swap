/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 10:14:12 by tidurand          #+#    #+#             */
/*   Updated: 2022/01/09 12:17:01 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_node
{
	int				value;
	struct s_node	*back;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	struct s_node	*begin;
	struct s_node	*end;
}	*t_stack;

//change list
int		is_empty_list(t_stack A_Stack);
t_stack	push_back(t_stack A_Stack, int x);
t_stack	push_front(t_stack Stack, int x);
t_stack	pop_back(t_stack Stack);
t_stack	pop_front(t_stack Stack);
//moves
t_stack	swap(t_stack Stack);
t_stack	rotate(t_stack Stack);
t_stack	reverse_rotate(t_stack Stack);
void	push(t_stack Src_Stack, t_stack Dest_Stack);

//errors
void	check_errors(char **av);
void	check_doubles(char **av);

//tools
void	putstr(char *s);
int		ft_strcmp(char *s1, char *s2);
int		ft_atoi(char *str);
int		list_len(t_stack A_Stack);
//char	**ft_split(char *s, char c);
int		ft_intlen(int *tab);
void	print_list(t_stack A_Stack); //remove at the end

/*void	push_swap_2(Stack Stack);
void push_swap_3(Stack Stack);
Stack	put_b(Stack stack, int ac);
int	smaller_first(Stack A_Stack);
int	smaller(Stack A_Stack, int len);
Stack	push_swap_first(Stack A_Stack, int nb);
void	push_swap_next(Stack A_Stack, Stack B_Stack, int len_a, int len_b);
void	push_swap_final(Stack A_Stack, Stack B_Stack);*/

#endif