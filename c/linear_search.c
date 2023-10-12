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

    int array[] = {1, 2, 3, 4, 5};
    int length = lengthof(array);
    int empty_array[] = {};

    assert(linear_search(1, array, length) == 1);
    assert(linear_search(10, array, length) == 0);
    assert(linear_search(1, empty_array, 0) == 0);

    println("All tests passed!");
}