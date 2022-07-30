/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlachkar <hlachkar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 03:42:59 by hlachkar          #+#    #+#             */
/*   Updated: 2022/07/29 10:15:03 by hlachkar         ###   ########.fr       */
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


#endif