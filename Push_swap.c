

#include "push_swap.h"

int main(int argc, char **argv)
{
    pile a = new_pile();
    pile b = new_pile();
    int *p;

    p = (int *)malloc(200);
    argv_to_a(&a, argc, argv);
    check_dup(a);
    is_sorted(a,argc);
    if(argc > 2 && argc < 30)
        minisort(argc, &a, &b);
    else
        bigsort(p, argv, &a, &b);
    print_stack(a);
    // free(p);
    // ft_free(&a);
}

// int main(int argc, char **arv)
// {
//     pile a = new_pile();
//     pile b = new_pile();
//     int i = 99, j = 1;
//     int ko[100] = {792,596,556,677,754,816,-448,648,-237,408,963,29,680,516,820,947,376,668,717,508,-138,917,-219,941,-742,632,-301,-386,553,-758,439,-10,465,-326,-348,198,-771,270,-533,-145,-74,-197,66,-638,161,-164,429,-945,-939,-228,-279,834,527,736,-491,355,-675,-287,-970,-657,332,983,353,-231,142,-839,-224,507,870,-958,-548,-713,-143,794,54,-915,104,493,101,-15,-101,-768,-528,226,-523,534,-527,838,286,-293,225,-705,-959,656,-171,-303,-954,-764,-136,-621};


//     while (i >= 0)
//     {
//         a = push_stack(a,ko[i]);
//         i--;
//     }
//     while(j <= argc-1)
//     {
//         if (!strcmp(arv[j], "pa"))
//         {
//             push_to_stack(&b,&a,"pa ");
//         }
//         if (!strcmp(arv[j], "pb"))
//         {
//             push_to_stack(&a,&b,"pb ");
//         }
//         if (!strcmp(arv[j], "ra"))
//         {
//             a = rotate_stack(a, "ra ");
//         }
//         if (!strcmp(arv[j], "rb"))
//         {
//             b = rotate_stack(b, "rb ");
//         }
//         if (!strcmp(arv[j], "rra"))
//         {
//             reverse_rotate(&a,"rra ");
//         }
//         if (!strcmp(arv[j], "rrb"))
//         {
//             reverse_rotate(&b,"rrb ");
//         }
//         j++;
//     }
//     print_stack(a);
//     printf("sqc\n");
//     print_stack(b);
// }
