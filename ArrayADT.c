#include <stdio.h>

struct Array
{
    int A[10];
    int size;
    int length;
};

void display(struct Array arr)
{
    for (int i = 0; i < arr.length; i++)
        printf("%d ", arr.A[i]);
}

void Append(struct Array *arr, int x)
{
    arr->A[arr->length++] = x;
}

void Insert(struct Array *arr, int index, int x)
{
    for(int i = arr->length; i > index; i--)
        arr->A[i] = arr->A[i - 1];
    
    arr->A[index] = x;
    arr->length++;
}

void Delete(struct Array *arr, int index)
{
    for(int i = index; i < arr->length - 1; i++)
        arr->A[i] = arr->A[i + 1];
    
    arr->length--;
}

int main()
{
    struct Array arr = {{1, 2, 3, 4, 5}, 10, 5};

    Insert(&arr, 2, 99);
    Delete(&arr, 0);
    display(arr);

    return 0;
}