
#include "push_swap.h"

void print_stack(pile st)
{
	if(stack_vide(st))
	{
		printf("Rien a afficher, la Pile est vide.\n");
		return;
	}

	while(!stack_vide(st))
	{
		printf("[%d]\n", st->i);
		st = st->next;
	}
}

void ft_putstr(char *str, int fd)
{
    int i;
    i = 0;

    while(str[i])
    {
        write(fd, &str[i], 1);
        i++;
    }
}

pile    new_pile(void)
{
    return NULL;
}

Bool   stack_vide(pile st)
{
    if(st == NULL)
        return true;
    return false;
}
