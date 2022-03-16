
#include "push_swap.h"

void mini_sort(int argc, pile *a, pile *b)
{
    if(argc == 3)
        sorttwo(a);
    else if(argc == 4)
        *a = sorttree(*a);
    else if(argc == 5)
        sortfour(a, b);
    else if(argc == 6)
        sortfive(a, b);
    else if(argc > 6 && argc < 30)
    {
        insertionsort_print(a, b, argc);
        push_back_to_a(a, b, argc - 1, 1);
    }
}
void big_sort(char **argv, pile *a, pile *b)
{
        int i;
        int *p;
        int t;

        i = 0;
        p = (int *)malloc(200);
        p[0] = get_min_value(*a) - 1;
        if(count_argc(argv) > 100)
            t = 11;
        else
            t = 4;
        getcunk(new_pile(), count_argc(argv), p, argv);
        while(i < t-1)
        {
            push_chunks_to_b(a, b, argv, p);
            i++;
        }
        insertionsort_print(a, b, count_argc(argv));
        pushmax(a, b, count_argc(argv));
        push_back_to_a(a, b, count_argc(argv) - 1, 11);
}
