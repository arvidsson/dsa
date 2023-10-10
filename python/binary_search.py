import argparse

parser = argparse.ArgumentParser()
parser.add_argument("item", type=int, help="The item to search for")
parser.add_argument("array", nargs="+", type=int, help="The array to search in")
args = parser.parse_args()


def binary_search(array, item):
    print("Searching for " + str(item) + " in " + str(array))
    left = 0
    right = len(array) - 1
    while left <= right:
        middle = int((left + right) / 2)
        if array[middle] < item:
            left = middle + 1
        elif array[middle] > item:
            right = middle - 1
        else:
            return True
    return False


# eg python3 binary_search.py 2 1 2 3 5 8
if binary_search(args.array, args.item):
    print("Found!")
else:
    print("Not found...")
