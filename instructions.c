
#include "push_swap.h"
pile    argv_to_a(pile *a, int argc, char **argv)
{
    while (argc > 1)
    {
        *a = push_stack(*a,ft_atoi(argv[argc - 1]));
        argc--;
    }
    return (new_pile());
}
pile    swap_stack(pile st, char *str)
{
    if(st->i && st->next)
    {
    swap(&st->i, &st->next->i);
    ft_putstr(str);
    }
    return(st);
}

pile    rotate_stack(pile st, char *str)
{
    pile temp;
    temp = st;
    while(temp != NULL && temp->next != NULL)
    {
        swap(&temp->next->i, &temp->i);
        temp = temp->next;
    }
    ft_putstr(str);
    return(st);
}

void    push_to_stack(pile *a, pile *b, char *str)
{
    int temp;
    temp = (*a)->i;
    *a = pop_stack(*a);
    *b = push_stack(*b, temp);
    ft_putstr(str);
}

void    reverse_rotate(pile *a, char *str)
{
    pile last;

    last = get_last(*a);
    last->next->next = *a;
    *a = last->next;
    last->next = NULL;
    ft_putstr(str);
}