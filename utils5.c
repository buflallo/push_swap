/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlachkar <hlachkar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 03:43:07 by hlachkar          #+#    #+#             */
/*   Updated: 2022/10/09 19:29:55 by hlachkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_dup(t_list *lst)
{
	t_list	*st;

	while (lst)
	{
		st = lst->next;
		while (st)
		{
			if (lst->content == st->content)
			{
				write(2, "Error\n", 6);
				exit(1);
			}
			st = st->next;
		}
		lst = lst->next;
	}
	return (0);
}

int	get_pos(t_list *lst, int min, int max)
{
	int	index;

	index = 0;
	while (lst)
	{
		if (lst->content >= min && lst->content <= max)
			break ;
		index++;
		lst = lst->next;
	}
	return (index);
}

void	rrr(t_list **lst, t_list **lst2)
{
	rr_sl(lst);
	rr_sl(lst2);
	write (1, "rrr\n", 4);
}
