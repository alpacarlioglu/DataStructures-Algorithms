#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*first=NULL;

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = (struct Node*)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

void displayRecursive(struct Node *p)
{
    if (p != NULL)
    {
        printf("%d ", p->data);
        displayRecursive(p = p->next);
    }
}

int count(struct Node *p)
{
    int c = 0;
    while (p != NULL)
    {
        c++;
        p = p->next;
    }

    return c;
}

int countRecursive(struct Node *p)
{
    if (p == NULL) 
        return 0;

    return countRecursive(p->next) + 1;
}

int add(struct Node *p)
{   
    int sum = 0;
    while (p) // Same as while (p != NULL)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

int main()
{
    int A[] = {3, 5, 7, 10, 15};
    
    create(A, 5);
    // displayRecursive(first);
    printf("%d ", add(first));

    return 0; 
}