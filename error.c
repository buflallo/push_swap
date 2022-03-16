
#include "push_swap.h"

void sorttwo(pile *a)
{
    if((*a)->i > (*a)->next->i)
        reverse_rotate(a, "rra\n");
}

void    ft_check_error(pile a, int argc)
{
	int	flag;
	pile st;
	
	flag = 0;
	while (!stack_vide(a) && a->next != NULL)
	{
		if (a->i > a->next->i)
			flag = 1;
		st = a->next;
		while(!stack_vide(st))
		{
			if(a->i == st->i)
				ft_print_error();
			st = st->next;
		}
		a = a->next;
	}
	if (flag == 0)
		exit(0);
}

int	ft_atoi(const char *str)
{
	long	a;
	long	k;

	k = 0;
	a = 1;
	if (!(*str))
		ft_print_error();
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if ((*str == '-' || *str == '+') && (*(str + 1) >= '0' && *(str + 1) <= '9'))
	{
		if (*str == '-')
			a = -1;
		str++;
	}
	while(*str)
	{
		if(*str < '0' || *str > '9')
			ft_print_error();
		k = k * 10 + *str - '0';
		str++;
	}
	if((k > (long)2147483648 && a == -1) || (k > (long)2147483647 && a != -1))
		ft_print_error();
	return (k * a);
}

void    ft_print_error()
{
	ft_putstr("error\n");
	exit(0);	
}