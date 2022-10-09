/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlachkar <hlachkar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 03:42:59 by hlachkar          #+#    #+#             */
/*   Updated: 2022/10/09 19:31:30 by hlachkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "Libft/libft.h"

void	ra(t_list **lst);
void	rb(t_list **lst);
void	rrb(t_list **lst);
void	rra(t_list **lst);
void	sa(t_list **lst);
void	sb(t_list **lst);
void	pa(t_list **lst1, t_list **lst2);
void	pb(t_list **lst1, t_list **lst2);
void	ss(t_list **lst1, t_list **lst2);
void	rrr(t_list **lst, t_list **lst2);
void	rr(t_list **lst);
int		compare(int a, int b);
void	sort(t_list **lst, t_list **lst2);
void	sort4_5(t_list **lst, int size, t_list **lst2);
int		not_sorted(t_list *lst);
int		check_dup(t_list *lst);
void	sort_three(t_list **lst, int one, int two, int three);
void	bringtotop(t_list **lst, int size, char name, int value);
int		get_pos(t_list *lst, int min, int max);
int		getlstindex(t_list *lst, int value);

#endif