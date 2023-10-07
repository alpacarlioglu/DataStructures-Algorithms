#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*first=NULL, *second = NULL, *third = NULL;

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

void create2(int A[], int n)
{
    int i;
    struct Node *t, *last;
    second = (struct Node*)malloc(sizeof(struct Node));
    second->data = A[0];
    second->next = NULL;
    last = second;

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
    while (p)
    {
        printf("%d ", p->data);
        displayRecursive(p->next);
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

int addRecursive(struct Node *p)
{
    if(!p) return 0;
    return addRecursive(p->next) + p->data;
}

int maxValue(struct Node *p)
{
    int max = -32768;
    while (p)
    {
        if (max < p->data)
            max = p->data;
        p = p->next;
    }
    
    return max;
}

struct Node* search(struct Node *p, int key)
{
    while (p)
    {
        if (key == p->data)
            return p;
        p = p->next;
    }

    return NULL;
}

struct Node* searchRecursive(struct Node *p, int key)
{
    if (p == NULL) return NULL;
    if (key == p->data)
        return p;
    return searchRecursive(p->next, key);
}

struct Node* searchImproved(struct Node* p, int key)
{
    struct Node *q = NULL;

    while (p)
    {
        if (key == p->data)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        
        q = p;
        p = p->next;
    }
}

void insert(struct Node *p, int index, int x)
{
    struct Node *t = NULL;

    if (index < 0 || index > count(p))
        return;

    t = (struct Node*)malloc(sizeof(struct Node));

    if (index == 0)
    {
        t->next = first;
        first = t;
        t->data = x;
    }
    else 
    {
        for (int i = 0; i < index - 1; i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
        t->data = x;
    }
}

void insertLast(struct Node *p, int x)
{
    struct Node *t = (struct Node*)malloc(sizeof(struct Node));

    while (p)
    {
        p = p->next;
    }

    p->next = t;
    t->data = x;
    t->next = NULL;
}

void sortedInsert(struct Node *p, int x)
{
    struct Node *t = (struct Node*)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;

    if (first == NULL)
        first = t;
    else
    {
        struct Node *q = NULL; // Tail pointer.

        while (p && p->data < x)
        {
            q = p;
            p = p->next;
        }

        if (p == first)
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

int removeNode(struct Node *p, int index)
{
    struct Node *q = NULL;
    int x = -1; // For storing data of deleted node

    if (index < 1  || index > count(p))
        return -1;

    if (index == 1)
    {
        q = first;
        x = first->data;
        first = first->next;
        free(q);
        return x;
    }
    else
    {
        for (int i = 0; i < index - 1 && p; i++)
        {
            q = p;
            p = p->next;
        }

        q->next = p ->next;
        x = p->data;
        free(p);
        return x;
    }
}

int isSorted(struct Node *p)
{
    int x = -65536;

    while (p)
    {
        if (p->data < x)
            return 0;

        x = p->data;
        p = p->next;
    }

    return 1;
}

void removeDuplicated(struct Node *p)
{
    struct Node *q, *r;

    while (p)
    {
        q = p;
        r = p->next;

        while (r)
        {
            if (p->data == r->data)
            {
                q->next = r->next;
                free(r);
                r = q->next;
            }
            else
            {
                q = r;
                r = r->next;
            }
        }

        p = p->next;
    }
}

void reverse1(struct Node *p)
{
    int *A, i = 0;
    struct Node *q = p;
    
    A = (int *)malloc(sizeof(int)*count(p));

    while (q)
    {
        A[i] = q->data;
        q = q->next;
        i++;
    }

    q = p;
    i--;
    
    while (q)
    {
        q->data = A[i];
        q = q->next;
        i--;
    }
}

void reverse2(struct Node *p)
{
    struct Node *q = NULL, *r = NULL;

    while (p)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }

    first = q;
}

void reverse3(struct Node *q, struct Node *p)
{
    if (p)
    {
        reverse3(p, p->next);
        p->next = q;
    }

    else    
        first = q;
}

int isLoop(struct Node *f)
{
    struct Node *p = NULL, *q = NULL;
    p = q = f;

    do
    {
        p = p->next;
        q = q->next;
        q = q != NULL ? q->next : NULL;
    } while (p && q && p != q);
    
    return p == q ? 1 : 0;
}

int main()
{
    int A[] = {3, 5, 7, 10, 15, 3, 5, 3};
    int B[] = {1, 2, 3, 4, 5};

    create(A, 5);
    create2(B, 5);

    printf("First\n");
    display(first);
    printf("\nSecond\n");
    display(second);
    return 0; 
}