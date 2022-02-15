
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

void    swap(int *y, int *z)
{
    int temp;

    temp = *y;
    *y = *z;
    *z = temp;
}

void ft_putstr(char *str)
{
    int i;
    i = 0;
    while(str[i])
    {
        write(1, &str[i], 1);
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

pile	push_stack(pile st, int x)
{
    pileElement *element;

    element = malloc(sizeof(*element));
    if(element == NULL)
        return(NULL);
    element->i = x;
    element->next = st;
    return element;
}
pile    pop_stack(pile st)
{
    pileElement *element;
    if(stack_vide(st))
        return new_pile();
    element = st;
    st = st->next;
    free(element);
    return(st);
}

void    check_dup(pile a)
{
	int flag;
	pile st;
	while(!stack_vide(a))
	{
		st = a->next;
		while(!stack_vide(st))
		{
			if(a->i == st->i)
			{
				ft_putstr("error\n");
				exit(0);
			}
			st = st->next;
		}
		a = a->next;
	}
}
void    reverse_rotate(pile *a, char *str)
{
    pile last;

    last = get_last(*a);
    last->next->next = *a;
    *a = last->next;
    last->next = NULL;
    printf("%s", str);
}
void insertionsort(pile *a, pile *b, int argc)
{
    int i;
    int temp;

    temp = argc;
    while(!stack_vide(*a))
    {
        i = getmin(*a);
        if(i <= temp / 2)
        {
            while(i > 1)
            {
                *a = rotate_stack(*a, "");
                i--;
            }
            push_to_stack(a, b, "");
        }
        else if(i == temp)
        {
            reverse_rotate(a, "");
        }
        else
        {
            while(i < temp)
            {
                reverse_rotate(a, "");
                i++;
            }
            push_to_stack(a, b, "");
        }
        temp--;
    }
}
int getmin(pile a)
{
    int i;
    int s;
    pile head;

    head = a;
    s = a->i;
    i = 1;
    while(!stack_vide(a))
    {
        if(a->i < s)
            s = a->i;
        a = a->next;  
    }
    while(head->i != s)
    {
        i++;
        head = head->next;
    }
    return(i);
}
pile get_last(pile a)
{
    if(stack_vide(a))
        return(a);
    while(!stack_vide(a->next->next))
    {
        a = a->next;
    }
    return(a);
}

void fill_a(pile *a, pile *b, int argc)
{
    while(argc > 1)
    {
        push_to_stack(b, a, "");
        argc--;
    }
}

pile cpy_stack(int argc, char **argv)
{
    pile cp = new_pile();
    while (argc > 1)
    {
        cp = push_stack(cp,ft_atoi(argv[argc - 1]));
        argc--;
    }
    return cp;
}

void   getcunk(pile cp, int argc, int *p, char **argv)
{
    pile b = new_pile();
    int i = 0,j = 1;
    cp = cpy_stack(argc, argv);

    insertionsort(&cp, &b, argc);
    fill_a(&cp, &b ,argc);
    while(i <= (argc-2))
    {
        if(i == (argc-2)/5)
            p[j++] = cp->i;
        else if (i == 2 * (argc-2)/5)
            p[j++] = cp->i;
        else if (i ==  3 * (argc-2)/5)
            p[j++] = cp->i;
        else if (i == 4 * (argc-2)/5)
            p[j++] = cp->i;
        else if (i ==  (argc-2))
            p[j++] = cp->i;
        i++;
        cp = cp->next;
    }
}

int getindex(pile a, int val)
{
    int i;
    pile head;

    head = a;
    i = 1;
    while(head->i != val)
    {
        i++;
        head = head->next;
    }
    return(i);
}
int lst_size(pile b)
{
    int len;

    len = 0;
    while(!stack_vide(b))
    {
        len++;
        b = b->next;
    }
    return len;
}

void    push_bready(pile *a, pile *b)
{
    int i;
    int j = 0;
    pile temp = *b;

    i = (*a)->i;
    while(!stack_vide(temp) && i > temp->i)
    {
        temp = temp->next;
        j++;
    }
    i = j;
    if(j > lst_size(*b) / 2)
    {
        while(j < lst_size(*b))
        {
            reverse_rotate(b, "rrb\n");
            j++;
        }
        push_to_stack(a, b, "pb\n");
        while(j - i >= 0)
        {
            *b = rotate_stack(*b, "rb\n");
            i++;
        }
    }
    else
    {
        while(j > 0)
        {
            *b = rotate_stack(*b, "rb\n");
            j--;
        }
        push_to_stack(a, b, "pb\n");
        while(i > 0)
        {
            reverse_rotate(b, "rrb\n");
            i--;
        }
    }
    
}

void extractchunk(pile *a, pile *b ,int *p ,int argc, char **argv, int max, int min)
{
    pile temp;
    int i;

    temp = cpy_stack(argc, argv);
    while(!stack_vide(temp))
    {
        if(temp->i <= max && temp->i > min)
        {
            i = getindex(*a, temp->i);
            printf("%d\n", i);
            if(i < argc/2)
            {
                while(i > 1)
                {
                    *a = rotate_stack(*a, "ra\n");
                    i--;
                }
                push_bready(a, b);
            }
            else if(i == argc)
            {
                reverse_rotate(a, "rra\n");
            }
            else
            {
                while(i < argc)
                {
                    reverse_rotate(a, "rra\n");
                    i++;
                }
                push_bready(a, b);
            }
            argc--;
        }
        temp = temp->next;
    }
}
int getminelem(pile a)
{
    int i;
    int s;
    pile head;

    head = a;
    s = a->i;
    i = 1;
    while(!stack_vide(a))
    {
        if(a->i < s)
            s = a->i;
        a = a->next;  
    }
    return(s);
}
void    push_back_to_a(pile *a, pile *b)
{
    int i = 0;
    while(!stack_vide(*b))
    {
        push_to_stack(b, a, "pa\n");
        i++;
    }
    while(i > 0)
    {
        *a = rotate_stack(*a, "ra\n");
        i--;        
    }
}
