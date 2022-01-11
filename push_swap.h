/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 13:11:39 by tidurand          #+#    #+#             */
/*   Updated: 2022/01/11 13:11:41 by tidurand         ###   ########.fr       */
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
void	push_a(t_stack a_stack, t_stack b_stack);
//errors
void	check_errors(char **av);
void	check_doubles(char **av);
void	check_errors_2(char *av);
void	check_doubles_2(int *nb);
int		already_sort(t_stack a_stack);
//tools
void	putstr(char *s);
int		ft_strcmp(char *s1, char *s2);
int		ft_atoi(char *str);
int		list_len(t_stack A_Stack);
int		ft_intlen(int *tab);
int		ft_strlen(char *s);
//parsing
int		*parsing_1(char **av, int ac);
int		*parsing_2(char **av, int *ac);
int		*value_to_index(int *nb, int len);
int		only_spaces(char *av);
char	*ft_new_av(char *av);
int		alone(char **av);
//shorter
void	three_pos(t_stack a_stack, t_stack b_stack, int *small, int *high);
void	cut_1(t_stack a_stack, t_stack b_stack, int *small, int len);
int		cut_2(t_stack a_stack, t_stack b_stack, int mark, int len);
void	elseif(t_stack a_stack, t_stack b_stack, int *small, int *high);
//push_b
t_stack	create_b_stack(t_stack a_stack, int len);
t_stack	push_b_section(t_stack a_stack, int mark, int small);
t_stack	push_b_non_sort(t_stack a_stack, int len34);
t_stack	push_rest(t_stack a_stack);
t_stack	push_all_except_one(t_stack a_stack);
//sort
void	cut_18(t_stack a_stack, t_stack b_stack, int *small, int len);
int		cut_38(t_stack a_stack, t_stack b_stack, int len);
int		cut_58(t_stack a_stack, t_stack b_stack, int len, int *this_len);
int		presort(t_stack a_stack, t_stack b_stack, int len, int mark);
void	last_good_n_last(t_stack a_stack);
void	sort_and_empty_b(t_stack a_stack, t_stack b_stack, int small, int high);
void	bad_n_up(t_stack a_stack, t_stack b_stack, int mark, int len34);
void	end_loop(t_stack a_stack, int this_len, int len);
//little push swap
void	push_swap_2(t_stack Stack);
void	push_swap_3(t_stack Stack);
void	push_swap_3_next(t_stack Stack);
void	push_swap_4(t_stack a_stack);
void	push_swap_4_next(t_stack a_stack, t_stack b_stack);
void	push_swap_5(t_stack a_stack);
void	push_swap_5_next(t_stack a_stack, t_stack b_stack);

#endif