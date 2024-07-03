#!/usr/bin/env python3
"""
Sort file for bst insertion
"""

import sys


class BST:
    def __init__(self):
        self.root = None

    def insert(self, val):
        if self.root is None:
            self.root = BSTNode(val)
            return
        self.insertR(self.root, val)

    def insertR(self, current_node, val):
        if current_node.val == val:
            print("seen already")
            return
        if val < current_node.val:
            if current_node.left is not None:
                self.insertR(current_node.left, val)
            else:
                current_node.left = BSTNode(val)
                return

        if val > current_node.val:
            if current_node.right is not None:
                self.insertR(current_node.right, val)
            else:
                current_node.right = BSTNode(val)
                return

    def pre_order_traversal(self, current, visit):
        if current is None:
            return
        visit(current)
        self.pre_order_traversal(current.left, visit)
        self.pre_order_traversal(current.right, visit)


class BSTNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

    def has_left(self):
        if self.left is None:
            return False
        return True

    def has_right(self):
        if self.right is None:
            return False
        return True


def bst_sort(input, bst, left, right):
    """
    bst_sort function, sorts an array for a mostly balaned bst tree sort
    """
    if left > right:
        return
    middle = (right + left) // 2
    bst.insert(input[middle])
    bst_sort(input, bst, left, middle - 1)
    bst_sort(input, bst, middle + 1, right)


def merge(array, left, middle, right):
    """
    merge routine
    """
    left_size = middle - left + 1
    right_size = right - middle
    left_array = [0] * left_size
    right_array = [0] * right_size
    for i in range(left_size):
        left_array[i] = array[left + i]
    for i in range(right_size):
        right_array[i] = array[middle + 1 + i]
    i = 0
    j = 0
    k = left
    while i < left_size and j < right_size:
        if left_array[i] <= right_array[j]:
            array[k] = left_array[i]
            k = k + 1
            i = i + 1
        else:
            array[k] = right_array[j]
            k = k + 1
            j = j + 1
    while i < left_size:
        array[k] = left_array[i]
        k = k + 1
        i = i + 1
    while j < right_size:
        array[k] = right_array[j]
        k = k + 1
        j = j + 1


def merge_sort(array, left, right):
    """
    merge sort
    """
    if left < right:
        middle = (right + left) // 2
        merge_sort(array, left, middle)
        merge_sort(array, middle + 1, right)
        merge(array, left, middle, right)


def print_BST_node(current_node):
    print(current_node.val, end=" ")


def bst_to_array(current, arr):
    if current is None:
        return
    arr.append(current.val)
    bst_to_array(current.left, arr)
    bst_to_array(current.right, arr)


def main():
    """
    main function
    """
    read_file_name = input("Input an input file name: ")
    try:
        with open(read_file_name, "r", encoding="utf-8") as file:
            data = file.read()
            print("File content successfully read.\n")
    except FileNotFoundError:
        print(f"Error: The file '{read_file_name}' does not exist.")
        sys.exit(1)
    data_array = data.splitlines()
    merge_sort(data_array, 0, len(data_array) - 1)
    bst = BST()
    bst_sort(data_array, bst, 0, len(data_array) - 1)
    print("Your data in sort order")
    print(data_array, "\n")
    print("Your data in order ready for bst insertion")
    bst_array = []
    bst.pre_order_traversal(bst.root, print_BST_node)
    print()
    bst_to_array(bst.root, bst_array)
    print(bst_array, "\n")
    write_file_name = input(
        "Input an output file name (Press enter for default value of 'myDataFile.txt'): "
    )
    if write_file_name == "":
        write_file_name = "myDataFile.txt"
    print("Writing data into ", write_file_name, "...")
    try:
        with open(write_file_name, "w", encoding="utf-8") as file:
            for item in bst_array:
                if item is not None:
                    file.write(item + "\n")
        print(f"Data successfully written to '{write_file_name}'.")
    except RuntimeError as e:
        print(f"Error writing to file '{write_file_name}': {e}")


if __name__ == "__main__":
    main()
