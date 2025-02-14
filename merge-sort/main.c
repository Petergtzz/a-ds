#include <stdio.h>

#include "../xorshift.c"

// Merge Sort Algorithm
// Merge(a, b)
// Does not matter if a or b are sorted 

// Time Complexity:
//  Best Case: Array is already sorted O(n)
//  Worst Case: Array is in asc to dec order O(n^2)

#define MAX_SIZE 10
#define ARRAY_COUNT(array) sizeof(array) / sizeof(array)[0]

typedef struct {
    uint32_t items[MAX_SIZE];
} Int32Array;

void merge_sort(Int32Array *a, Int32Array *b, uint32_t c[])
{
    // Find lenth of a and b (sometimes they vary, but not in this case)
    uint32_t n = ARRAY_COUNT(a->items); // len a
    uint32_t m = ARRAY_COUNT(b->items); // len b
    
    // Three indexes 
    int i = 0; int j = 0; int k = 0; 
    
    // Check for empty arrays or if a ith element is less than b ith element
    while((i < n) || (j < m))
    {
        if ((j == m) || (i < n && a->items[i] < b->items[j]))
        {
            c[k++] = a->items[i++];
        }
        else
        {
            c[k++] = b->items[j++];
        }
    }
}

int main(int argc, char **argv)
{
    Int32Array a = {0};
    Int32Array b = {0};
    
    // Seed
    XorShift32_state state_1 = {.a = 0xB5556};
    XorShift32_state state_2 = {.a = 0xB2456};

    printf("Unsorted Array A:   Unsorted Array b:\n");
    for(int i = 0; i < MAX_SIZE; i++)
    {
        uint32_t num_1 = xorshift32(&state_1);
        uint32_t num_2 = xorshift32(&state_2);

        a.items[i] = num_1;
        b.items[i] = num_2;
        printf("%10d\t%12d\n", a.items[i], b.items[i]); 
    }

    uint32_t c[20] = {0};
    merge_sort(&a, &b, c);
    printf("Merged Array:\n");
    for(int i = 0; i < ARRAY_COUNT(c); i++)
    {
        printf("%d\n", c[i]);

    }
    return 0;
} 
