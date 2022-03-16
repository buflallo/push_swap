

#include "push_swap.h"
#include "get_next_line.h"


int main(int argc, char **argv)
{
    pile a = new_pile();
    pile b = new_pile();
    char *str;
    int j = 0;


    argv_to_a(&a, argc, argv);
    ft_check_error(a,argc);
    str = get_next_line(0);
    while (str)
    {
        if (!strcmp(str, "pa\n"))
            push_to_stack(&b,&a,"");
        else if (!strcmp(str, "pb\n"))
            push_to_stack(&a,&b,"");
        else if (!strcmp(str, "ra\n"))
            a = rotate_stack(a, "");
        else if (!strcmp(str, "rb\n"))
            b = rotate_stack(b, "");
        else if (!strcmp(str, "rra\n"))
            reverse_rotate(&a,"");
        else if (!strcmp(str, "rrb\n"))
            reverse_rotate(&b,"");
        else if (!strcmp(str, "sa\n"))
            a = swap_stack(a,"");
        else if (!strcmp(str, "sb\n"))
            b = swap_stack(b,"");
        else
        {
            ft_print_error();
        }
        str = get_next_line(0);
        
    }
    ft_result(a);
}