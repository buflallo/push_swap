
#include "push_swap.h"
void    argv_to_a(pile *a, int argc, char **argv)
{
    while (argc > 1)
    {
        *a = push_stack(*a,ft_atoi(argv[argc - 1]));
        argc--;
    }
}
pile    swap_stack(pile st, char *str)
{
    int temp;

    if(st->i && st->next)
    {
        temp = st->next->i;
        st->next->i = st->i;
        st->i = temp;
        ft_putstr(str,1);
    }
    return(st);
}

pile    rotate_stack(pile st, char *str)
{
    pile temp;
    int temp_i;

    temp = st;
    while(temp != NULL && temp->next != NULL)
    {
        temp_i = temp->next->i;
        temp->next->i = temp->i;
        temp->i = temp_i;
        temp = temp->next;
    }
    ft_putstr(str,1);
    return(st);
}

void    push_to_stack(pile *a, pile *b, char *str)
{
    int temp;
    temp = (*a)->i;
    *a = pop_stack(*a);
    *b = push_stack(*b, temp);
    ft_putstr(str,1);
}

void    reverse_rotate(pile *a, char *str)
{
    pile last;

    last = get_last(*a);
    last->next->next = *a;
    *a = last->next;
    last->next = NULL;
    ft_putstr(str,1);
}