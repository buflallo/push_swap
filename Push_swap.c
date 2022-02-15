
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


int main(int argc, char **argv)
{
    pile a = new_pile();
    pile b = new_pile();
    int i = argc;
    int *p;
    pile cp;

    p = (int *)malloc(24);
    
    while (i > 1)
    {
        a = push_stack(a,ft_atoi(argv[i - 1]));
        i--;
    }
    check_dup(a);

    if(argc == 4)
        a = sorttree(a);
    else if(argc == 5)
        sortfour(&a, &b);
    else if(argc == 6)
        sortfive(&a, &b);
    else
    {
        p[0] = getminelem(a) - 1;
        getcunk(cp, argc, p, argv);
        extractchunk(&a, &b , p, argc, argv,p[1],p[0]);
        push_back_to_a(&a, &b);
        extractchunk(&a, &b , p, argc, argv,p[2],p[1]);
        push_back_to_a(&a, &b);
        extractchunk(&a, &b , p, argc, argv,p[3],p[2]);
        push_back_to_a(&a, &b);
        extractchunk(&a, &b , p, argc, argv,p[4],p[3]);
        push_back_to_a(&a, &b);
    }
    print_stack(a);
    printf("----------\n");
    print_stack(b);
    return(0);
}
