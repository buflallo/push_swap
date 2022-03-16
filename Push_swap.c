

#include "push_swap.h"

int main(int argc, char **argv)
{
    pile a = new_pile();
    pile b = new_pile();

    argv_to_a(&a, argc, argv);
    ft_check_error(a,argc);
    if(argc > 2 && argc < 30)
        mini_sort(argc, &a, &b);
    else
        big_sort(argv, &a, &b);
    // print_stack(a);
    // free(p);
    // ft_free(&a);
}

// int main(int argc, char **argv)
// {
//     pile a = new_pile();
//     pile b = new_pile();
//     char *str;
//     int j = 0;


//     argv_to_a(&a, argc, argv);
//     str = get_next_line(0);
//     while (str)
//     {
//         if (!strcmp(str, "pa\n"))
//             push_to_stack(&b,&a,"pa ");
//         if (!strcmp(str, "pb\n"))
//             push_to_stack(&a,&b,"pb ");
//         if (!strcmp(str, "ra\n"))
//             a = rotate_stack(a, "ra ");
//         if (!strcmp(str, "rb\n"))
//             b = rotate_stack(b, "rb ");
//         if (!strcmp(str, "rra\n"))
//             reverse_rotate(&a,"rra ");
//         if (!strcmp(str, "rrb\n"))
//             reverse_rotate(&b,"rrb ");
//         if (!strcmp(str, "sa\n"))
//             a = swap_stack(a,"sa ");
//         if (!strcmp(str, "sb\n"))
//             b = swap_stack(b,"sb ");
//         str = get_next_line(0);
//     }
    // while(j <= argc-1)
    // {
    //     if (!strcmp(arv[j], "pa"))
    //     {
    //         push_to_stack(&b,&a,"pa ");
    //     }
    //     if (!strcmp(arv[j], "pb"))
    //     {
    //         push_to_stack(&a,&b,"pb ");
    //     }
    //     if (!strcmp(arv[j], "ra"))
    //     {
    //         a = rotate_stack(a, "ra ");
    //     }
    //     if (!strcmp(arv[j], "rb"))
    //     {
    //         b = rotate_stack(b, "rb ");
    //     }
    //     if (!strcmp(arv[j], "rra"))
    //     {
    //         reverse_rotate(&a,"rra ");
    //     }
    //     if (!strcmp(arv[j], "rrb"))
    //     {
    //         reverse_rotate(&b,"rrb ");
    //     }
    //     j++;
    // }
    // print_stack(a);
    // printf("sqc\n");
    // print_stack(b);
// }
