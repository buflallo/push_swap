
#include "push_swap.h"

void sorttwo(pile *a)
{
    if((*a)->i > (*a)->next->i)
        reverse_rotate(a, "rra\n");
}

void    check_dup(pile a)
{
	int flag;
	pile st;
	while(!stack_vide(a))
	{
		st = a->next;
		while(!stack_vide(st))
		{
			if(a->i == st->i)
				ft_error();
			st = st->next;
		}
		a = a->next;
	}
}

void    is_sorted(pile a, int argc)
{
	int	flag;

	flag = 0;
	while (!stack_vide(a) && a->next != NULL)
	{
		if (a->i > a->next->i)
			flag = 1;
		a = a->next;
	}
	if (flag == 0)
		exit(0);
}

int	ft_atoi(const char *str)
{
	long	i;
	long	a;
	long	k;

	k = 0;
	a = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if ((str[i] == '-' || str[i] == '+') && (str[i + 1] >= '0' && str[i + 1] <= '9'))
	{
		if (str[i] == '-')
			a = -1;
		i++;
	}
	while(str[i])
	{
		if(str[i] < '0' || str[i] > '9')
			ft_error();
		k = k * 10 + str[i] - '0';
		i++;
	}
	if((k > (long)2147483648 && a == -1) || (k > (long)2147483647 && a != -1))
		ft_error();
	return (k * a);
}

void    ft_error()
{
	ft_putstr("error\n");
	exit(0);	
}