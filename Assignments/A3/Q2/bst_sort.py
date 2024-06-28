#!/usr/bin/env python3
"""
Sorting Script for BST's
"""

import math
import os
import subprocess


def bst_sort(array, sort_array, index, middle, radius):
    """
    bst_sort function, sorts an array for a mostly balaned bst tree sort
    """
    # base case
    if index == len(array):
        return
    if index % 2 == 1:
        radius *= -1
    sort_array[index] = array[middle + radius]
    bst_sort(array, sort_array, index + 1, middle, radius)


def merge(array, left, middle, right):
    """
    merge function
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
    merge function
    """
    if left < right:
        middle = math.floor((left + right) / 2)
        merge_sort(array, left, middle)
        merge_sort(array, middle + 1, right)
        merge(array, left, middle, right)


def run():
    """
    run function
    """
    file_name = "forbidden.txt"
    with open(file_name, "r", encoding="utf-8") as file:
        data = file.read()
    data_array = data.split()
    print(data_array)
    merge_sort(data_array, 0, len(data_array) - 1)
    bst_array = [None] * len(data_array)
    bst_sort(data_array, bst_array, 0, math.floor(len(data_array) / 2), 0)
    print(data_array)


if __name__ == "__main__":
    run()
