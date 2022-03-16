
#include "push_swap.h"

void   getcunk(pile cp, int argc, int *p, char **argv)
{
    pile b;
    int i;
    int j;

    b = new_pile();
    i = 0,
    j = 1;
    cp = cpy_args(argc, argv);
    insertionsort(&cp, &b, argc);
    fill_a(&cp, &b ,argc);
    while(i <= (argc-2))
    {
        if(i == (argc-2)/4)
            p[j++] = cp->i;
        else if (i == 2 * (argc-2)/4)
            p[j++] = cp->i;
        else if (i ==  3 * (argc-2)/4)
            p[j++] = cp->i;
        else if (i ==  (argc-2))
            p[j++] = cp->i;
        i++;
        cp = cp->next;
    }
}

void   getcunk_hundred(pile cp, int argc, int *p, char **argv)
{
    pile b;
    int i;
    int j;
    int k;

    i = 0;
    j = 1;
    cp = cpy_args(argc, argv);
    insertionsort(&cp, &b, argc);
    fill_a(&cp, &b ,argc);
    while(i <= (argc-2))
    {
        k = 0;
        while(k++ < 11)
        {
            if(i == k * (argc-2)/11)
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
    int j;

    i = 0;
    j = count_argc(argv);
    temp = cpy_args(j, argv);
    while(!stack_vide(temp) && i <= j)
    {
        if(p[k + 1] && temp->i <= p[k + 1] && temp->i > p[k])
        {
            pushchunk(a, b, j, temp);
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