/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlachkar <hlachkar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 03:43:10 by hlachkar          #+#    #+#             */
/*   Updated: 2022/07/30 03:20:41 by hlachkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_list **lst)
{
	t_list	*last;
	t_list	*head;
	t_list *tmp;

	last = ft_lstnew((*lst)->content);
	head = (*lst)->next;
	free(*lst);
	tmp = ft_lstlast(head);
	tmp->next = last;
	*lst = head;
	write (1, "rb\n", 3);
}

void	ra(t_list **lst)
{
	t_list	*last;
	t_list	*head;
	t_list *tmp;

	last = ft_lstnew((*lst)->content);
	head = (*lst)->next;
	free(*lst);
	tmp = ft_lstlast(head);
	tmp->next = last;
	*lst = head;
	write (1, "ra\n", 3);
}

void	rrb(t_list **lst)
{
	t_list	*last;
	t_list	*head;
	t_list *tmp;

	last = ft_lstBeforLast(*lst);
	tmp = ft_lstnew(last->next->content);
	free(last->next);
	last->next = NULL;
	ft_lstadd_front(lst, tmp);
	write (1, "rrb\n", 4);
}


void	rra(t_list **lst)
{
	t_list	*last;
	t_list	*head;
	t_list *tmp;

	last = ft_lstBeforLast(*lst);
	tmp = ft_lstnew(last->next->content);
	free(last->next);
	last->next = NULL;
	ft_lstadd_front(lst, tmp);
	write (1, "rra\n", 4);
}

void	rr_sl(t_list **lst)
{
	t_list	*last;
	t_list	*head;
	t_list *tmp;

	last = ft_lstBeforLast(*lst);
	tmp = ft_lstnew(last->next->content);
	free(last->next);
	last->next = NULL;
	ft_lstadd_front(lst, tmp);
	// write (1, "rra\n", 4);
}

void rrr(t_list **lst, t_list **lst2)
{
	rr_sl(lst);
	rr_sl(lst2);
	write (1, "rrr\n", 4);
}