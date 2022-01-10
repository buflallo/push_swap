#include <stdio.h>
#include <stdlib.h>

typedef struct s_stack{
	int n;
	struct s_stack *nex;
}stack;

stack *create(int b)
{
	stack *soo;

	soo = (stack*)malloc(sizeof(stack));
	if(!soo)
		return NULL;
	soo->n = b;
	soo->nex = NULL;
	return soo;
}

void add(stack **head, int b)
{
	stack *tmp;
	stack *ts;

	if(!(*head))
	{
		*head = create(b);
		return;
	}
	tmp = (stack*)malloc(sizeof(stack));
	tmp->n = b;
	tmp->nex = NULL;
	ts = *head;
	*head = tmp;
	tmp->nex = ts;
}

stack *last(stack *head)
{
	while(head->nex->nex)
		head = head->nex;
	return head;
}

void sa(stack **a)
{
	stack *tmp;

	tmp = (*a)->nex;
	(*a)->nex = (*a)->nex->nex;
	tmp->nex = *a;
	*a = tmp;
}

void ra(stack **a)
{
	stack *tmp1;
	stack *tmp2;

	tmp1 = *a; 
	
	tmp2 = last(*a);
	tmp2->nex->nex = tmp1;
	tmp1 = tmp2->nex;
	tmp2->nex = NULL;
	*a = tmp1;
}

void rra(stack **a)
{
	stack *tmp1;
	stack *tmp2;

	tmp1 = *a; 
	
	tmp2 = last(*a);
	tmp2->nex->nex = tmp1;
	*a = tmp1->nex;
	tmp2->nex->nex->nex = NULL;
}

void print(stack *a)
{
	int i = 0;
	while(a)
	{	
		printf("%d,",a->n);
		a = a->nex;
	}
}

stack *full_stack(int *a,int size)
{
	int i;
	stack *tes;
	tes = (stack*)malloc(sizeof(stack));
	tes->nex = NULL;
	tes->n = a[0];

	i = 1;
	while (i < size)
	{
		add(&tes, a[i]);
		i++;
	}
	return tes;
}

void sort_tre(stack **tes)
{
	stack *tmp;
	int a,b,c;
	tmp = *tes;
	a = (*tes)->n;
	b = (*tes)->nex->n;
	c = (*tes)->nex->nex->n;


	if (a > b && b < c && c < a)
		rra(tes);
	if (a > b && b < c && c > a)
		sa(tes);
	if (a > b && b > c)
	{
		sa(tes);
		ra(tes);
	}
	if (a < b && a > c)
		ra(tes);
	if (a < b && a < c)
	{
		ra(tes);
		sa(tes);
	}
}

void pa(stack **a,stack **b)
{
	stack *tmp;

	tmp = *b;
	add(a,(*b)->n);
	*b = (*b)->nex;
	free(tmp);
}

void sort_five(stack **pol,stack **tes)
{
	int a,c,d;

	pa(pol,tes);
	pa(pol,tes);
	// print(*tes);
	sort_tre(tes);
	a = (*pol)->n;
	c = (*tes)->n;
	d = (*tes)->nex->n;
	printf("%d < %d",a,c);
	if(a < c)
		pa(tes,pol);
	else
		while(a >= c)
		{
			ra(tes);
		}
}

int main()
{
	int sta[5] = {8,3,10,2,5};
	stack *tes;
	stack *pol;
	pol = NULL;

	
	tes = full_stack(sta, 5);
	// print(tes);
	sort_five(&pol,&tes);
	// print(tes);
}

// 5 2 10 3 8

// 10 3 8    2  5

// 5 3 8 10    2

// 3 5 8 10


// 4 8 5 6 3 

// 563 84
// sor3
// 356 84
// 8 > 3 && 8 > 6 ==> pa  compare head of list if b.n < a.n => pa()
3568 4
4 > 3 && 4 < 5  pa sa



// 2358 4
// 4 > 2 ==> 3582 -> 5823 -> pa 45823 -> 34582 -> 23458

3582 4 -> 5823 4 -> 45823 -> 


// 2358 8235 5823 45823 34582 23458