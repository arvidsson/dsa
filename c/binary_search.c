#include "common.h"

int binary_search(int value, int array[], int length)
{
    printf("Searching for %d in ", value);
    print_array(array, length);
    printf("\n");

    int left = 0;
    int right = length - 1;

    while (left <= right)
    {
        int middle = (int)((left + right) / 2);
        if (array[middle] < value)
        {
            left = middle + 1;
        }
        else if (array[middle] > value)
        {
            right = middle - 1;
        }
        else
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

    assert(binary_search(2, array, length) == 1);
    assert(binary_search(10, array, length) == 0);
    assert(binary_search(1, empty_array, 0) == 0);

    println("All tests passed!");
}