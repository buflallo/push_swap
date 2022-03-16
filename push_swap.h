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
void    sortfour(pile *a, pile *b);
void    sortfive(pile *a, pile *b);
Bool	stack_vide(pile st);
pile	push_stack(pile st, int x);
int		ft_atoi(const char *str);
pile    swap_stack(pile st, char *str);
void    ft_putstr(char *str);
void    swap(int *y, int *z);
void    print_stack(pile st);
pile    rotate_stack(pile st, char *str);
pile    new_pile(void);
void    push_to_stack(pile *a, pile *b, char *str);
pile    pop_stack(pile st);
pile    prep_four(pile a);
pile    prep_five(pile a);
void    check_dup(pile a);
void    insertionsort(pile *a, pile *b, int argc);
int     getmin(pile a);
pile    get_last(pile a);
void    reverse_rotate(pile *a, char *str);
void    fill_a(pile *a, pile *b, int argc);
void    getcunk(pile cp, int argc, int *p, char **argv);
pile    cpy_args(int argc, char **argv);
int     getindex(pile a, int val);
int     getminelem(pile a);
void    push_back_to_a(pile *a, pile *b, int argc, int div);
int     getmaxindex(pile a);
void    pushmax(pile *a, pile *b, int argc);
void    insertionsortt(pile *a, pile *b, int argc);
void    push_chunks_to_b(pile *a, pile *b, char **argv, int *p);
int     lst_size(pile b);
void    is_sorted(pile a, int argc);
void    getcunk_hundred(pile cp, int argc, int *p, char **argv);
void    ft_free(pile *a);
void    minisort(int argc, pile *a, pile *b);
void    bigsort(int *p, char **argv, pile *a, pile *b);
pile    argv_to_a(pile *a, int argc, char **argv);
int     count_argc(char **argv);
void    ft_error();
void    pushchunk(pile *a, pile *b, int j, pile temp);

#endif