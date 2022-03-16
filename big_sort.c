
#include "push_swap.h"

void   getcunk(pile cp, int argc, int *p, char **argv)
{
    pile b;
    int i;
    int j;
    int k;
    int div;

    b = new_pile();
    i = 0,
    j = 1;
    argv_to_a(&cp, argc, argv);
    insertionsort(&cp, &b, argc);
    fill_a(&cp, &b ,argc);
    div = lst_size(cp);
    if (div > 100)
        div = 11;
    else
        div = 4;
    while(i <= (argc-2))
    {
        k = 0;
        while(k++ < div)
        {
            if(i == k * (argc-2)/div)
                p[j++] = cp->i;
        }
        i++;
        cp = cp->next;
    }
}

void    push_chunks_to_b(pile *a, pile *b, char **argv, int *p)
{
    pile temp;
    int i;
    static int k;

    i = 0;
    temp = new_pile();
    argv_to_a(&temp, count_argc(argv), argv);
    while(!stack_vide(temp))
    {
        if(p[k + 1] && temp->i <= p[k + 1] && temp->i > p[k])
        {
            pushchunk(a, b, count_argc(argv), temp);
        }
        temp = temp->next;
    }
    k++;
}
void pushchunk(pile *a, pile *b, int j, pile temp)
{
    int i;

    i = getindex(*a, temp->i);
    if(i == j)
        reverse_rotate(a, "rra\n");
    else if(i <= (j - 1) / 2)
    {
        while(i > 1)
        {
            *a = rotate_stack(*a, "ra\n");
            i--;
        }
    }
    else if(i >= (j - 1) / 2)
    {
        while(i <= j - 3)
        {
            reverse_rotate(a, "rra\n");
            i++;
        }
    }
    push_to_stack(a, b, "pb\n");  
}

void    push_back_to_a(pile *a, pile *b, int argc, int div)
{
    int i = 0;
    while(!stack_vide(*b) && i < argc / div)
    {
        push_to_stack(b, a, "pa\n");
        i++;
    }
}