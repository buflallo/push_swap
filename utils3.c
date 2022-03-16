
#include "push_swap.h"

pile	push_stack(pile st, int x)
{
    pileElement *element;

    element = malloc(sizeof(*element));
    if(element == NULL)
        return(NULL);
    element->i = x;
    element->next = st;
    return element;
}

pile    pop_stack(pile st)
{
    pileElement *element;
    if(stack_vide(st))
        return new_pile();
    element = st;
    st = st->next;
    free(element);
    return(st);
}

int get_min_index(pile a)
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
    while(head->i != s)
    {
        i++;
        head = head->next;
    }
    return(i);
}
pile get_last(pile a)
{
    if(stack_vide(a))
        return(a);
    while(!stack_vide(a->next->next))
    {
        a = a->next;
    }
    return(a);
}
