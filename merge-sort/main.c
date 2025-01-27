#include <stdio.h>


// Merge Sort Algorithm
// Merge(a, b)
// Does not matter is a or b are sorted 

// Time Complexity:
//  Best Case: Array is already sorted O(n)
//  Worst Case: Array is in asc to dec order O(n^2)

#define MAX_SIZE 10

typedef struct {
    int32_t items[MAX_SIZE];
    // int32_t count;
    // int32_t capacity;
} Int32Array;


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
