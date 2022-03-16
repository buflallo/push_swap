
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
    pile temp,temp1;
    pile head;
    int i;
    static int k;
    int hold1,hold2;

    i = 0;
    temp1 = *a;
    while (!stack_vide(temp1))
    {
        temp = temp1;
        while(!stack_vide(temp))
        {
            if(p[k + 1] && temp->i <= p[k + 1] && temp->i > p[k])
            {    
                hold1 = getindex(*a, temp->i);
                temp = temp->next;
                break;
            }
                // pushchunk(a, b, count_argc(argv), temp);
            temp = temp->next;
        }
        pushchunk(a, b, count_argc(argv), hold1);
        temp1 = temp1->next;
    }
    
    k++;
}

int get_closer(int hold1,int hold2)
{
    int actions1;
    int actions2;
    if (hold1 > 50)
        actions1 = 100 - hold1; 
    else
        actions1 = hold1;
    if (hold2 > 50)
        actions2 = 100 - hold2; 
    else
        actions2 = hold2;
    if (actions1 < actions2)
        return hold1;
    else
        return hold2;
}

void pushchunk(pile *a, pile *b, int j, int val)
{
    int i;

    i = val;
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