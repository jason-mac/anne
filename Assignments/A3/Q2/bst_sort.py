#!/usr/bin/env python3
"""
Sort file for bst insertion
"""

import sys


def bst_sort(arr):
    """
    bst_sort function, sorts an array for a mostly balaned bst tree sort
    """
    # base case
    new_arr = [None] * len(arr)
    middle = len(arr) // 2
    radius = 0
    for i in range(len(arr)):
        increment = 0
        if i % 2 == 1:
            increment = -radius
        if i % 2 == 0:
            increment = radius
            radius += 1
        new_arr[i] = arr[middle + increment]
    return new_arr


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


def run():
    """
    run function
    """
    read_file_name = input("Input a file name: ")
    try:
        with open(read_file_name, "r", encoding="utf-8") as file:
            data = file.read()
            print("File content successfully read.\n")
    except FileNotFoundError:
        print(f"Error: The file '{read_file_name}' does not exist.")
        sys.exit(1)
    data_array = data.split()
    merge_sort(data_array, 0, len(data_array) - 1)
    print("You're file in sort order")
    print(data_array, "\n")
    print("Your file in order ready for bst insertion")
    bst_array = bst_sort(data_array)
    print(bst_array)
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
    run()
