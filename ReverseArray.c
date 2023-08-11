#include <stdio.h>

struct Array
{
    int A[10];
    int size;
    int length;
};

void Display(struct Array arr)
{
    for(int i = 0; i < arr.length; i++)
        printf("%d ", arr.A[i]);
}

int Reverse(struct Array *arr)
{
    int *B = (int *)malloc(arr->length *sizeof(int));
    int i, j;

    for(i = arr->length - 1, j = 0; i >= 0; i--, j++)
        B[j] = arr->A[i];

    for(i = 0; i < arr->length; i++) 
        arr->A[i] = B[i];
}

int main()
{
    struct Array arr = {{23, 22, 21, 20, 19, 18}, 10, 6};

    Reverse(&arr);
    Display(arr);   
    return 0;
}