#ifndef push_swap_h
# define push_swap_h

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
    typedef struct pileElement
    {
        int i;
        struct pileElement *next;
    }pileElement, *pile;

    typedef enum
    {
        false,
        true
    }Bool;
void    sorttwo(pile *a);
pile    sorttree(pile st);
pile    prep_four(pile a);
void    sortfour(pile *a, pile *b);
pile    prep_five(pile a);
void    sortfive(pile *a, pile *b);
Bool	stack_vide(pile st);
pile    new_pile(void);
pile	push_stack(pile st, int x);
pile    pop_stack(pile st);
int     lst_size(pile b);
int     getindex(pile a, int val);
pile    get_last(pile a);
int     getmaxindex(pile a);
void    pushmax(pile *a, pile *b, int argc);
int     get_min_index(pile a);
void    push_to_stack(pile *a, pile *b, char *str);
void    ft_free(pile *a);
int     get_min_value(pile a);
void    argv_to_a(pile *a, int argc, char **argv);



pile    rotate_stack(pile st, char *str);
void    reverse_rotate(pile *a, char *str);
pile    swap_stack(pile st, char *str);


void    ft_check_error(pile a, int argc);
void    ft_print_error();
void    getcunk(pile cp, int argc, int *p, char **argv);
void    push_back_to_a(pile *a, pile *b, int argc, int div);
void    fill_a(pile *a, pile *b, int argc);
void    mini_sort(int argc, pile *a, pile *b);
void    big_sort(char **argv, pile *a, pile *b);
void    insertionsort_print(pile *a, pile *b, int argc);
void    push_chunks_to_b(pile *a, pile *b, char **argv, int *p);
void    pushchunk(pile *a, pile *b, int j, pile temp);


int		ft_atoi(const char *str);
void    ft_putstr(char *str);
void    print_stack(pile st);
void    insertionsort(pile *a, pile *b, int argc);
int     count_argc(char **argv);



#endif