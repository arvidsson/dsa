import sys
import unittest
import argparse


def linear_search(array, item):
    print("Searching for " + str(item) + " in " + str(array))
    for element in array:
        if element == item:
            return True
    return False


class Test(unittest.TestCase):
    def test_found(self):
        self.assertTrue(linear_search([1, 2, 3, 4, 5], 2))

    def test_not_found(self):
        self.assertFalse(linear_search([1, 2, 3, 4, 5], 10))

    def test_empty_list(self):
        self.assertFalse(linear_search([], 10))


if __name__ == "__main__":
    if len(sys.argv) == 1:
        unittest.main()
    else:
        parser = argparse.ArgumentParser()
        parser.add_argument("item", type=int, help="The item to search for")
        parser.add_argument("array", nargs="+", type=int, help="The array to search in")
        args = parser.parse_args()
        if linear_search(args.array, args.item):
            print("Found!")
        else:
            print("Not found...")
