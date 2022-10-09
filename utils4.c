/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlachkar <hlachkar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 03:43:07 by hlachkar          #+#    #+#             */
/*   Updated: 2022/10/09 19:20:41 by hlachkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **lst, t_list **lst2)
{
	int	min;
	int	max;
	int	push_it;
	int	size;
	int	i;

	i = 0;
	size = ft_lstsize(*lst);
	push_it = ((size - 5) / 4) + 1;
	min = ft_get_smallest(*lst, compare);
	max = min + (push_it - 1);
	while (i < push_it)
	{
		bringtotop(lst, size, 'a', get_pos(*lst, min, max));
		pb (lst, lst2);
		if ((*lst2)->content < (max + min) / 2 && ft_lstsize(*lst2) >= 2)
			rb(lst2);
		size = ft_lstsize(*lst);
		i++;
	}
}

int	is_there(int content, t_list *b)
{
	while (b)
	{
		if (b->content == content)
			return (1);
		b = b->next;
	}
	return (0);
}

void	push_to_a(t_list **lst, t_list **lst2, int tmp, t_list *last_node)
{
	if ((*lst2)->content == (*lst)->content - 1)
		pa (lst2, lst);
	else if ((*lst2)->content < (*lst)->content
		&& (((*lst2)->content > last_node->content)
			|| tmp == last_node->content))
	{
		pa (lst2, lst);
		ra (lst);
	}
	else
	{
		bringtotop(lst2, ft_lstsize(*lst2), 'b', \
		getlstindex(*lst2, (*lst)->content - 1));
		pa (lst2, lst);
	}
}

void	put_back(t_list **lst, t_list **lst2)
{
	t_list	*last_node;
	int		tmp;

	last_node = ft_lstlast(*lst);
	tmp = last_node->content;
	while (*lst2)
	{
		if (is_there((*lst)->content - 1, *lst2))
		{
			push_to_a(lst, lst2, tmp, last_node);
		}
		else
			rra (lst);
		last_node = ft_lstlast(*lst);
	}
	while (ft_lstlast(*lst)->content < (*lst)->content)
		rra(lst);
}

void	sort(t_list **lst, t_list **lst2)
{
	int		size;

	size = ft_lstsize(*lst);
	while (size > 5)
	{
		push(lst, lst2);
		size = ft_lstsize(*lst);
	}
	sort4_5(lst, size, lst2);
	put_back(lst, lst2);
}
