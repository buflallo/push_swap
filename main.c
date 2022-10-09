/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlachkar <hlachkar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 03:43:07 by hlachkar          #+#    #+#             */
/*   Updated: 2022/10/09 19:31:19 by hlachkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	getindex(char **av, int size, int value)
{
	int	i;
	int	pos;

	i = 1;
	pos = 0;
	while (i < size)
	{
		if (value > ft_atoi(av[i]))
			pos++;
		i++;
	}
	return (pos);
}

int	check(char *c)
{
	int	i;

	i = 0;
	if (c[i] == '-' || c[i] == '+')
		i++;
	if (c[i] == '\0')
		return (0);
	while (c[i])
	{
		if (!ft_isdigit(c[i]))
			return (0);
		i++;
	}
	return (1);
}

void	init_stack(t_list **stack, int argc, char **av)
{
	int	i;
	int	content;

	i = 1;
	*stack = NULL;
	while (i < argc && check(av[i]) && (ft_atoi(av[i]) != 0 || (av[i][0] != '0' \
	|| ft_strncmp(av[i], "-0", 3) || ft_strncmp(av[i], "+0", 3))))
	{
		if ((ft_atoi(av[i]) < 0 && av[i][0] != '-')
		|| (ft_atoi(av[i]) > 0 && av[i][0] == '-')
		|| (ft_atoi(av[i]) == -1 && ft_strncmp(av[i], "-1", 3) != 0))
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		content = getindex(av, argc, ft_atoi(av[i]));
		ft_lstadd_back(stack, ft_lstnew(content));
		i++;
	}
	if (av[i] && (!check(av[i]) || (ft_atoi(av[i]) == 0 && (av[i][0] != '0' || \
	ft_strncmp(av[i], "-0", 3) || ft_strncmp(av[i], "-0", 3)))))
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

void	sort_three(t_list **lst, int one, int two, int three)
{
	if (one < two && two < three)
		return ;
	if (one < two && one < three)
	{
		sa (lst);
		ra (lst);
	}
	else if (one > two && one < three)
		sa (lst);
	else if (one < two && one > three)
		rra (lst);
	else if (one > two && two < three)
		ra (lst);
	else if (one > two && two > three)
	{
		sa (lst);
		rra (lst);
	}
}

int	main(int argc, char *av[])
{
	t_list	*lst;
	t_list	*lst2;

	lst = NULL;
	lst2 = NULL;
	init_stack(&lst, argc, av);
	check_dup(lst);
	if (!not_sorted(lst))
		return (0);
	if (ft_lstsize(lst) <= 5)
	{
		if (ft_lstsize(lst) == 2)
			sa(&lst);
		else
			sort4_5(&lst, ft_lstsize(lst), &lst2);
	}
	else
		sort(&lst, &lst2);
	return (0);
}
