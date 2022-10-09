/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlachkar <hlachkar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 06:46:18 by hlachkar          #+#    #+#             */
/*   Updated: 2022/10/09 19:30:51 by hlachkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_list **lst1, t_list **lst2)
{
	t_list	*temp;

	if (*lst1)
	{
		ft_lstadd_front (lst2, ft_lstnew((*lst1)->content));
		temp = *lst1;
		*lst1 = (*lst1)->next;
		free(temp);
		write (1, "pb\n", 3);
	}
}

void	pa(t_list **lst1, t_list **lst2)
{
	t_list	*temp;

	if (*lst1)
	{
		ft_lstadd_front (lst2, ft_lstnew((*lst1)->content));
		temp = *lst1;
		*lst1 = (*lst1)->next;
		free(temp);
		write (1, "pa\n", 3);
	}
}

void	sb(t_list **lst)
{
	int		size;
	t_list	*temp;
	t_list	*head;

	size = ft_lstsize (*lst);
	if (size >= 2)
	{
		head = *lst;
		temp = (*lst)->next;
		ft_lstadd_front (lst, ft_lstnew(head->next->content));
		head->next = head->next->next;
		free(temp);
		write (1, "sb\n", 3);
	}
}

void	sa(t_list **lst)
{
	int		size;
	t_list	*temp;
	t_list	*head;

	size = ft_lstsize (*lst);
	if (size >= 2)
	{
		head = *lst;
		temp = (*lst)->next;
		ft_lstadd_front (lst, ft_lstnew(head->next->content));
		head->next = head->next->next;
		free(temp);
		write (1, "sa\n", 3);
	}
}

void	ss(t_list **lst1, t_list **lst2)
{
	int	size1;
	int	size2;

	size1 = ft_lstsize (*lst1);
	size2 = ft_lstsize (*lst2);
	if (size1 >= 2)
		sa (lst1);
	if (size2 >= 2)
		sb (lst2);
	write (1, "ss\n", 3);
}
