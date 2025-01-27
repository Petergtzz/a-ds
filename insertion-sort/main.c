#include <stdio.h>

#include "xorshift.c"

// Insertion Sort Algorithm
// Input  a: a[a,...,n-1]
// Output b: b[a,...,n-1]
// b is same as a, but sorted

// Time Complexity:
//  Best Case: Array is already sorted O(n)
//  Worst Case: Array is in asc to dec order O(n^2)

#define MAX_SIZE 10

typedef struct {
    int32_t items[MAX_SIZE];
    // int32_t count;
    // int32_t capacity;
} Int32Array;

void swap(int32_t *x, int32_t *y)
{    
    int32_t temp = *x;
    *x = *y;
    *y = temp; 
}


void insertion_sort(Int32Array *input)
{
    // Loop over all a
    for(int i = 1; i < MAX_SIZE; i++)
    {
        // Assign ith element to j 
        int32_t j = i;
        // While j > 0 and j < i-1
        while(j > 0 && input->items[j] < input->items[j-1])
        {
            // Swap numbers
            swap(&input->items[j], &input->items[j-1]);
            j--;
        }
    }
}


int main(int argc, char **argv)
{
    Int32Array input = {0};
    
    // Seed
    XorShift32_state state = {.a = 0xB5556};

    printf("Unsorted Array:\n");
    for(int i = 0; i < MAX_SIZE; i++)
    {
        int32_t number = xorshift32(&state);
        input.items[i] = number;
        printf("%d\n", input.items[i]);
    }

    insertion_sort(&input);
    printf("Sorted Array:\n");
    for(int i = 0; i < MAX_SIZE; i++)
    {
        printf("%d\n", input.items[i]);
    }
    return 0;
} 
