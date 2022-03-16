
#include "push_swap.h"

pile sorttree(pile st)
{
    int top;
    int middle;
    int bottom;

    top = st->i;
    middle = st->next->i;
    bottom = st->next->next->i;
    if(top > middle && middle < bottom && top < bottom)
        swap_stack(st, "sa\n");
    else if(top > middle && middle > bottom)
    {
        rotate_stack(st, "ra\n");
        swap_stack(st, "sa\n");
    }
    else if(top > middle && middle < bottom && top > bottom)
        rotate_stack(st, "ra\n");
    else if(top < middle && middle > bottom && top < bottom)
    {
        swap_stack(st, "sa\n");
        rotate_stack(st, "ra\n");
    }
    else if(top < middle && middle > bottom && top > bottom)
    {
        rotate_stack(st, "ra\n");
        rotate_stack(st, "ra\n");
    }
    return(st);
}

pile   prep_four(pile a)
{
    int top;
    int two;
    int three;
    int four;

    top = a->i;
    two = a->next->i;
    three = a->next->next->i;
    four = a->next->next->next->i;
    if(top > two && two < three && two < four)
        a = rotate_stack(a, "ra\n");
    else if(three < top && three < two && three < four)
    {
        a = rotate_stack(a, "ra\n");
        a = rotate_stack(a, "ra\n");
    }
    else if(four < top && four < two && four < three)
    {
        reverse_rotate(&a, "rra\n");
    }
    return(a);
}

pile    prep_five(pile a)
{
    int top;
    int two;
    int three;
    int four;
    int five;

    top = a->i;
    two = a->next->i;
    three = a->next->next->i;
    four = a->next->next->next->i;
    five = a->next->next->next->next->i;
    if(top > two && two < three && two < four && two < five)
        a = rotate_stack(a, "ra\n");
    else if(three < top && three < two && three < four && three < five)
    {
        a = rotate_stack(a, "ra\n");
        a = rotate_stack(a, "ra\n");
    }
    else if(four < top && four < two && four < three && four < five)
    {
        reverse_rotate(&a, "rra\n");
        reverse_rotate(&a, "rra\n");
    }
    else if(five < top && five < two && five < three && five < four)
    {
        reverse_rotate(&a, "rra\n");
    }
    return(a);
}

void    sortfour(pile *a, pile *b)
{
    *a = prep_four(*a);
    push_to_stack(a, b, "pb\n");
    *a = sorttree(*a);
    push_to_stack(b, a, "pa\n");
}

void    sortfive(pile *a, pile *b)
{
    *a = prep_five(*a);
    push_to_stack(a, b, "pb\n");
    sortfour(a, b);
    push_to_stack(b, a, "pa\n");
}
