
#include "push_swap.h"

void minisort(int argc, pile *a, pile *b)
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
        insertionsortt(a, b, argc);
        push_back_to_a(a, b, argc - 1, 1);
    }
}
void bigsort(int *p, char **argv, pile *a, pile *b)
{
        int i = 0;
        p[0] = getminelem(*a) - 1;
        if(count_argc(argv) > 350)
        {
            getcunk_hundred(new_pile(), count_argc(argv), p, argv);
            while(i < 10)
            {
                push_chunks_to_b(a, b, argv, p);
                i++;
            }
            insertionsortt(a, b, count_argc(argv));
            push_back_to_a(a, b, count_argc(argv) - 1, 11);
            pushmax(a, b, count_argc(argv));
        }
        else
        {
            getcunk(new_pile(), count_argc(argv), p, argv);
            while(i < 3)
            {
                push_chunks_to_b(a, b, argv, p);
                i++;
            }
            insertionsortt(a, b, count_argc(argv));
            push_back_to_a(a, b, count_argc(argv) - 1, 4);
            pushmax(a, b, count_argc(argv));
        }
}
