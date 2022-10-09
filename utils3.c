/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlachkar <hlachkar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 03:43:07 by hlachkar          #+#    #+#             */
/*   Updated: 2022/10/09 19:19:21 by hlachkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bringtotop(t_list **lst, int size, char name, int value)
{
	int	med;

	med = size / 2;
	if (value <= med)
	{
		while (value)
		{
			if (name == 'b')
				rb(lst);
			else if (name == 'a')
				ra(lst);
			value--;
		}
	}
	else
	{
		while (value != size)
		{
			if (name == 'b')
				rrb(lst);
			else if (name == 'a')
				rra(lst);
			value++;
		}
	}
}

int	compare(int a, int b)
{
	if (a <= b)
		return (1);
	else
		return (0);
}

int	getlstindex(t_list *lst, int value)
{
	int	i;

	i = 0;
	while (lst && lst->content != value)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	sort4_5(t_list **lst, int size, t_list **lst2)
{
	int	small;

	if (size == 4 || size == 5)
	{
		small = ft_get_smallest(*lst, compare);
		small = getlstindex(*lst, small);
		bringtotop(lst, size, 'a', small);
		pb(lst, lst2);
	}
	if (size == 5)
	{
		small = ft_get_smallest(*lst, compare);
		small = getlstindex(*lst, small);
		bringtotop(lst, size - 1, 'a', small);
		pb(lst, lst2);
	}
	sort_three(lst, (*lst)->content, (*lst)->next->content, \
	(*lst)->next->next->content);
	if (size == 4 || size == 5)
		pa(lst2, lst);
	if (size == 5)
		pa(lst2, lst);
}

int	not_sorted(t_list *lst)
{
	while (lst->next)
	{
		if (lst->content > lst->next->content)
			return (1);
		lst = lst->next;
	}
	return (0);
}
