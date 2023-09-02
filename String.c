#include <stdio.h>
#include <stdlib.h>

int findLength(char A[])
{
    int i = 0;
    while (A[i] != '\0')
    {   
        A[i++];
    }
    return i;
}

void lowerCaseString(char *A)
{
    int i = 0;
    while (A[i] != '\0')
    {
        A[i] += 32;
        i++;
    }
    printf("%s ", A);
}

void countWords(char A[])
{
    int i = 0, c = 1;
    while (A[i] != '\0')
    {
        if (A[i] == 32)
            c++;
        i++;
    }
    printf("%d", c);
}

void reverseString(char *A)
{
    int i = 0, c = 0;
    while (A[i] != '\0')
    {
        i++;
        c++;
    }

    char B[sizeof(c) * 4];
    int k;

    for (i = c - 1, k = 0; i >= 0; i--, k++)
    {
        B[k] = A[i]; 
    }

    B[k] = '\0';
    printf("%s", B);
}

int main()
{
    char name[] = "ALP_ACARLIOGLU";
    char name2[] = {'A', 'L', 'P', '\0'};
    char A[] = {'W', '\0'};

    char word[] = "Where are you coming from?";
    char space[] = "A";

    // printf("%c ", A[0] + 32); // Lower the 'W' char.

    reverseString(name);

    return 0;
}