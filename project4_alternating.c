// Daniel Misherky
// U93099650
// This program checks if a sequence alternates between positive
// and negative integers using pointer arithmetic
#include <stdio.h>
#include <malloc.h>

int is_alternating_sequence(int *sequence, int n); // initialization of function to check if sequence is alternating
int main()
{
    int n, *p; // n is length of sequence, p is pointer to access array elements
    printf("Enter length of the sequence: ");
    scanf("%d", &n); // user inputs length of sequence
    printf("Enter numbers of the sequence: ");
    int *sequence = malloc(n*sizeof(int));
    for(p = &sequence[0]; p < &sequence[n]; p++) // p is pointer to access array elements using for loop
    {
        scanf("%d", p); // user inputs sequence
    }

    if(is_alternating_sequence(sequence, n)) // if function returns 1, sequence is alternating
    {
        printf("yes");
    }
    else // if function returns 0, sequence is not alternating
    {
        printf("no");
    }

    return 0;
}
int is_alternating_sequence(int *sequence, int n)
{
    int *p; // pointer to access array elements
    int alternating = 1; // flag variable set to 1
    for(p=sequence; p<sequence+n-1; p++) // pointer arithmetic used to access array elements
    {
        if(!((*p>0 && *(p+1)<0) ||(*p<0 && *(p+1)>0))) // checks if term is positive and next term is negative or vice versa
        {
            alternating = 0; // if not, set flag variable to 0
            break; // gets out of loop since sequence is not alternating
        }
    }
    return alternating; // return flag variable
    
}