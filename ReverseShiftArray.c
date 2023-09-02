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
    for(int i = 0; i < arr.length; i++)
        printf("%d ", arr.A[i]);
}

int reverse(struct Array *arr)
{
    int *B = (int *)malloc(arr->length *sizeof(int));
    int i, j;

    for(i = arr->length - 1, j = 0; i >= 0; i--, j++)
        B[j] = arr->A[i];

    for(i = 0; i < arr->length; i++) 
        arr->A[i] = B[i];
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int reverse2(struct Array *arr)
{
    int i, j;

    for(int i = 0, j = arr->length - 1; i < j; i++, j--)
        swap(&arr->A[i], &arr->A[j]);
}

void rightShift(struct Array *arr)
{
    for(int i = 0; i < arr->length; i++)
        arr->A[i] = arr->A[i + 1];
    arr->A[arr->length - 1] = 0;
}

void leftRotate(struct Array *arr)
{
    int temp = arr->A[0];

    for(int i = 0; i < arr->length; i++)
        arr->A[i] = arr->A[i + 1];
    arr->A[arr->length - 1] = temp;
}

int main()
{
    struct Array arr = {{23, 22, 21, 20, 19, 18}, 10, 6};

    leftRotate(&arr);
    display(arr);   
    return 0;
}