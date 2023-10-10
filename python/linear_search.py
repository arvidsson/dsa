import argparse

parser = argparse.ArgumentParser()
parser.add_argument("item", type=int, help="The item to search for")
parser.add_argument("array", nargs="+", type=int, help="The array to search in")
args = parser.parse_args()


def linear_search(array, item):
    print("Searching for " + str(item) + " in " + str(array))
    for element in array:
        if element == item:
            return True
    return False


# eg python3 linear_search.py 2 1 2 3 5 8
if linear_search(args.array, args.item):
    print("Found!")
else:
    print("Not found...")
