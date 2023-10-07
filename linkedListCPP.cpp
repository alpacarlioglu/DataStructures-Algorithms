#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class LinkedList
{
private:
    Node *first;
public:
    LinkedList()
    { 
        first = NULL; 
    };

    LinkedList(int *arr, int size);
    ~LinkedList();

    void Display();
    void Insert(int index, int x);
    int Delete(int index);
    int Length(); 
};

LinkedList::LinkedList(int *arr, int size)
{
    first = new Node;
    first->data = arr[0];
    first->next = NULL;

    Node *last = new Node;
    last = first;
    last->next = NULL;

    for (int i = 1; i < size; i++)
    {
        Node *t = new Node;
        t->data = arr[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

LinkedList::~LinkedList()
{
    Node *p = first;
    
    while (first)
    {
        first = first->next;
        delete p;
        p = first;
    }
}

void LinkedList::Display()
{
    Node *p = first;

    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

int LinkedList::Length()
{
    int len = 0;
    Node *p = first;

    while (p)
    {
        len++;
        p = p->next;
    }

    return len;
}

void LinkedList::Insert(int index, int x)
{
    Node *t, *p = first;

    if (index < 0 || index > Length())
        return;

    t = new Node;
    t->data = x;
    t->next = NULL;

    if (index == 0)
        first = t;
    else
    {
        for (int i = 0; i < index - 1; i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
}

int LinkedList::Delete(int index)
{
    Node *p = NULL, *q = NULL;
    int x = -1;

    if (index < 1 || index > Length())
        return -1;

    if (index == 1)
    {
        p = first;
        x = first->data;
        first = first->next;
        delete(p);
        return x;
    }
    else
    {
        p = first;
        for (int i = 0; i < index -1 && p; i++)
        {
            q = p;
            p = p->next;
        }

        q->next = p->next;
        x = p->data;
        delete(p);
        return x;
    }
}

int main()
{
    int A[] = {10, 20, 30, 40, 50};
    LinkedList l(A, 5);

    l.Delete(1);

    l.Display();

    return 0;
}

