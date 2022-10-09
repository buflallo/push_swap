/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlachkar <hlachkar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 03:43:07 by hlachkar          #+#    #+#             */
/*   Updated: 2022/10/09 04:32:20 by hlachkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int getindex(char **av, int size, int value)
{
    int i;
    int pos;

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


void print_stack(t_list *stack)
{
    t_list *tmp;

    tmp = stack;
    while (tmp)
    {
        printf("%d ", tmp->content);
        tmp = tmp->next;
    }
    printf("\n");
}

int check(char *c)
{
    int i;

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

void init_stack(t_list **stack, int argc, char **av)
{
    int i;
    int content;

    i = 1;
    *stack = NULL;
    while (i < argc && av[i] && check(av[i]) && (ft_atoi(av[i]) != 0 || (av[i][0] != '0' || ft_strncmp(av[i], "-0", 3) || ft_strncmp(av[i], "-0", 3))))
    {
        if ((ft_atoi(av[i]) < 0  && av[i][0] != '-') || (ft_atoi(av[i]) > 0  && av[i][0] == '-') || (ft_atoi(av[i]) == -1 && ft_strncmp(av[i], "-1", 3) != 0))
        {
            write(2,"Error\n", 6);
            exit(1);
        }
        content = getindex(av, argc, ft_atoi(av[i]));
        ft_lstadd_back(stack, ft_lstnew(content));
        i++;
    }
    if (av[i] && (!check(av[i]) || (ft_atoi(av[i]) == 0 && (av[i][0] != '0' || ft_strncmp(av[i], "-0", 3) || ft_strncmp(av[i], "-0", 3)) )))
    {
        write(2,"Error\n", 6);
        exit(1);
    }
}
void    SortThree(t_list **lst, int one, int two, int three)
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

void bringtotop(t_list **lst, int size, char name, int value)
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


int compare(int a, int b)
{
	if (a <= b)
		return (1);
	else
		return (0);
}

int getlstindex(t_list *lst, int value)
{
    int i;

    i = 0;
    while (lst && lst->content != value)
    {
        lst = lst->next;
        i++;
    }
    // printf("index--%d\n", i);
    return (i);
}

void    sort4_5(t_list **lst, int size, t_list **lst2)
{
    int small;
    
    if (size == 4 || size == 5)
    {
        small = ft_get_smallest(*lst, compare);
        small = getlstindex(*lst, small);
        bringtotop(lst, size, 'a', small);
        pb(lst, lst2);
    }
    if(size == 5)
    {
        small = ft_get_smallest(*lst, compare);
        small = getlstindex(*lst, small);
        bringtotop(lst, size - 1, 'a', small);
        pb(lst, lst2);
    }
    SortThree(lst, (*lst)->content, (*lst)->next->content, (*lst)->next->next->content);
    if (size == 4 || size == 5)
        pa(lst2, lst);
    if(size == 5)
        pa(lst2, lst);
}

int not_sorted(t_list *lst)
{
    while(lst->next)
    {
        if (lst->content > lst->next->content)
            return 1;
        lst = lst->next;
    }
    return 0;
}

int	get_pos(t_list *lst, int min, int max)
{
	int	pos1;
    int index;

	pos1 = 0;
    index = 0;
	while (lst)
	{
		if (lst->content >= min && lst->content <= max)
			return index;
		index++;
		lst = lst->next;
	}
    return pos1;
}

void push(t_list **lst, t_list **lst2)
{
    int	min;
	int	max;
	int	pushed;
	int	size;
	int	i;

	i = 0;
	size = ft_lstsize(*lst); //112 -- 85 
	pushed = ((size - 5) / 4) + 1; // 27 -- 21
	min = ft_get_smallest (*lst, compare); 
	max = min + (pushed - 1); // 0 + 27 - 1 = 26
	while (i < pushed)
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

void	put_back(t_list **lst, t_list **lst2)
{
	t_list	*lastnode;
    int     tmp;

	lastnode = ft_lstlast(*lst);
    tmp = lastnode->content;
	while (*lst2)
	{
		if (is_there ((*lst)->content - 1, *lst2))
		{
			if ((*lst2)->content == (*lst)->content - 1)
            {
				pa (lst2, lst);
            }
			else if ((*lst2)->content < (*lst)->content
				&& (((*lst2)->content > lastnode->content) || tmp == lastnode->content ))
			{
				pa (lst2, lst);
				ra (lst);
			}
			else
            {
                bringtotop(lst2, ft_lstsize(*lst2), 'b', getlstindex(*lst2, (*lst)->content - 1));
                pa (lst2, lst);
            }
		}
		else
        {
			rra (lst);
        }
		lastnode = ft_lstlast(*lst);
	}
    while (ft_lstlast(*lst)->content < (*lst)->content)
        rra(lst);
}

void	sort(t_list **lst, t_list **lst2)
{
	int		size;
	// t_list	*lastdup;

    size = ft_lstsize(*lst);
	while (size > 5)
	{
		push(lst, lst2);
		size = ft_lstsize(*lst);
	}
	sort4_5(lst, size, lst2);
	put_back(lst, lst2);
}

int check_dup(t_list *lst)
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
    return(0);
}

int main(int argc, char *av[])
{
    t_list *lst;
    t_list *lst2;
    // t_list *stack;

    lst = NULL;
    lst2 = NULL;
    // while (i < argc && ft_atoi(av[i]) != 0)
    // {
    //     ft_lstadd_back(&stack, ft_lstnew(ft_atoi(av[i])));
    //     i++;
    // }
    init_stack(&lst, argc, av);
    if (!not_sorted(lst))
        return(0);
    check_dup(lst);
    if (ft_lstsize(lst) <= 5)
    {
        if (ft_lstsize(lst) == 2)
            sa(&lst);
        else
            sort4_5(&lst, ft_lstsize(lst), &lst2);
    }
    else
        sort(&lst, &lst2);
}

