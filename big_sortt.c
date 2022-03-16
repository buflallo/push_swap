
#include "push_swap.h"

void insertionsort_print(pile *a, pile *b, int argc)
{
    int i;
    while(!stack_vide(*a))
    {
        i = get_min_index(*a);
        if(i <= argc / 2)
        {
            while(i > 1)
            {
                *a = rotate_stack(*a, "ra\n");
                i--;
            }
            push_to_stack(a, b, "pb\n");
        }
        else if(i == argc)
            reverse_rotate(a, "rra\n");
        else
        {
            while(i < argc)
            {
                reverse_rotate(a, "rra\n");
                i++;
            }
            push_to_stack(a, b, "pb\n");
        }
        argc--;
    }
}

void fill_a(pile *a, pile *b, int argc)
{
    while(argc > 1)
    {
        push_to_stack(b, a, "");
        argc--;
    }
}

void insertionsort(pile *a, pile *b, int argc)
{
    int i;
    while(!stack_vide(*a))
    {
        i = get_min_index(*a);
        if(i == argc)
            reverse_rotate(a, "");
        else if(i <= argc / 2)
        {
            while(i > 1)
            {
                *a = rotate_stack(*a, "");
                i--;
            }
            push_to_stack(a, b, "");
        }
        else
        {
            while(i < argc)
            {
                reverse_rotate(a, "");
                i++;
            }
            push_to_stack(a, b, "");
        }
        argc--;
    }
}

void pushmax(pile *a, pile *b, int argc)
{
    int i;
    int size;

    i = 0;
    size = lst_size(*b);
    while(!stack_vide(*b))
    {
        i = getmaxindex(*b);
        if(i > lst_size(*b) / 2 && i != 1)
        {
            while(i <= lst_size(*b))
            {
                reverse_rotate(b, "rrb\n");
                i++;
            }
        }
        else if(i <= size / 2 && i != 1)
        {
            while(i > 1)
            {
                *b = rotate_stack(*b, "rb\n");
                i--;
            }
        }
        push_to_stack(b, a, "pa\n");
    }
}

int count_argc(char **argv)
{
    int i;

    i = 0;
    while(argv[i])
        i++;
    return (i);
}