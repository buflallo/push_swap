
#include "push_swap.h"

int getindex(pile a, int val)
{
    int i;
    pile head;

    head = a;
    i = 1;
    while(head->i != val && head->next)
    {
        i++;
        head = head->next;
    }
    return(i);
}

int lst_size(pile b)
{
    int len;

    len = 0;
    while(!stack_vide(b))
    {
        len++;
        b = b->next;
    }
    return len;
}

int get_min_value(pile a)
{
    int i;
    int s;
    pile head;

    head = a;
    s = a->i;
    i = 1;
    while(!stack_vide(a))
    {
        if(a->i < s)
            s = a->i;
        a = a->next;  
    }
    return(s);
}

int getmaxindex(pile a)
{
    int i;
    int s;
    pile head;

    head = a;
    s = a->i;
    i = 1;
    while(!stack_vide(a))
    {
        if(a->i >= s)
            s = a->i;
        a = a->next;  
    }
    while(head->i != s)
    {
        i++;
        head = head->next;
    }
    return(i);
}

void ft_free(pile *a)
{
    int i;
    pile *temp;

    temp = a;
    i = 0;
    while(!stack_vide(*a))
    {
        *a = (*a)->next;
        free(*temp);
        temp = a;
        i++;
    }
}
