import argparse

parser = argparse.ArgumentParser()
parser.add_argument("array", nargs="+", type=int, help="The array to sort")
args = parser.parse_args()


def bubble_sort(array):
    n = len(array)
    for i in range(n):
        for j in range(n - 1 - i):
            if array[j] > array[j + 1]:
                array[j], array[j + 1] = array[j + 1], array[j]
    print(array)


# eg python3 bubble_sort.py 2 1 2 3 5 8 10 400 11 15 58 23
bubble_sort(args.array)
