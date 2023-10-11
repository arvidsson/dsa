# Data Structures and Algorithms

Notes and implementations in various programming languages.

## Algorithms

### Linear Search

The most simple search. It loops over the array, checks each element until a match is found or the entire array has been searched.

#### pseudocode

```
for value in array
    if value == item
        return true
return false
```

Time Complexity: O(n)

### Binary Search

Algorithm to find a value in a **sorted** array. It looks at the middle element and compares to the value. If the value is lower or higher then the half where the value cannot be found is eliminated. The remaining half is then cut in half, the middle value compared and this is repeated until the value is found or the remaining half being empty and thus the value was not in the array at all.

#### pseudocode

```
left = 0
right = length(array) - 1
while left <= right
    middle = floor((left + right) / 2)
    if array[middle] < item
        left = middle + 1
    else if array[middle] > item
        right = middle - 1
    else
        return true
return false
```

Time Complexity: O(log n)

### Bubble Sort

Sort in place algorithm. It repeatedly loops through the array, comparing each element with the one after it and swaps them if the element is larger than its neighbour. These loops are repeated until the list is sorted. The larger values "bubbles" up to the top.

#### pseudocode

```
for i in range(length(array) - 1)
    for j in range(length(array) - i - 1)
        if array[j] > array[j + 1]
            swap(array[j], array[j + 1])
```

Time Complexity: O(N^2)
