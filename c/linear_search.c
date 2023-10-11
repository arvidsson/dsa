#include "common.h"

int linear_search(int value, int array[], int length)
{
    printf("Searching for %d in ", value);
    print_array(array, length);
    printf("\n");

    for (int i = 0; i < length; i++)
    {
        if (value == array[i])
        {
            return 1;
        }
    }

    return 0;
}

int main(int argc, char **argv)
{
    println("Running tests...");

    assert(linear_search(1, (int[]){1, 2, 3, 4, 5}, 5) == 1);
    assert(linear_search(1, (int[]){}, 0) == 0);

    println("All tests passed!");
}