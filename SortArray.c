#include <stdio.h>
#include <stdlib.h>

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

void insertSort(struct Array *arr, int x)
{
    int i = arr->length - 1;
    if (arr->length == arr->size) return;
    
    while (i >= 0 && x < arr->A[i])
    {
        arr->A[i + 1] = arr->A[i];
        i--;
    }

    arr->A[i + 1] = x;
    arr->length++;
}

int isSorted(struct Array arr)
{
    int i;
    for (i = 0; i < arr.length - 1; i++)
    {
        if (arr.A[i] > arr.A[i + 1])
            return 0;
    }
    return 1;
}

struct Array* merge(struct Array *arr1, struct Array *arr2)
{   
    int i, j, k;
    i = j = k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else
            arr3->A[k++] = arr2->A[j++];
    }

    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i]; 
    for (; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j]; 

    arr3->length = arr1->length + arr2->length;
    arr3->size = 10;

    return arr3;
}

int main()
{
    struct Array arr1 = {{1, 2, 6, 7, 23}, 10, 5};
    struct Array arr2 = {{10, 11, 12, 13, 14}, 10, 5};
    struct Array *arr3;
    arr3 = merge(&arr1, &arr2);
    
    display(*arr3);

    return 0;
}