#!/usr/bin/env python3
"""
Main Module

This module reads data from a file and outputs 
text such that the line by line order of the 
output would generate a balanced Binary Search Tree 
when using a standard insertion algorithm for BSTs.
Usage:
    Run this module directly and ensure you have a desired input text within the same directory
"""
import sys

from bst import BST
from helper import bst_sort, bst_to_array, merge_sort  # , print_BST_node


def main():
    """
    Main function algorithm:
    1) Read Data (from text file)
    2) Sort Data (for bst insertion)
    3) Output Data (for verification)
    4) Write Data (into output file)
    """
    # Get file name from user input
    read_file_name = input("Input an input file name: ")

    # Read data from file into data_array
    try:
        with open(read_file_name, "r", encoding="utf-8") as file:
            data_array = file.read().splitlines()
            print("File content successfully read.\n")
    except FileNotFoundError:
        print(f"Error: The file '{read_file_name}' does not exist.")
        sys.exit(1)

    # Sort data using merge sort in ascending order
    merge_sort(data_array, 0, len(data_array) - 1)

    # Create and populate BST that is height balanced
    bst = BST()
    bst_sort(data_array, bst, 0, len(data_array) - 1)

    # Display sorted array and BST contents for verification
    print("Your data in sort order")
    print(data_array, "\n")
    print("Your data in order ready for bst insertion")
    bst_array = []
    # bst.pre_order_traversal(bst.root, print_BST_node)
    print()
    bst_to_array(bst.root, bst_array)
    print(bst_array, "\n")

    # Prompt user for output file name
    output_file_name = input(
        "Input an output file name (Press enter for default value of 'output.txt'): "
    )
    if output_file_name == "":
        output_file_name = "output.txt"

    # Write BST data to output file
    print("Writing data into ", output_file_name, "...")
    try:
        with open(output_file_name, "w", encoding="utf-8") as file:
            for item in bst_array:
                if item is not None:
                    file.write(item + "\n")
        print(f"Data successfully written to '{output_file_name}'.")
    except IOError as e:
        print(f"Error writing to file '{output_file_name}': {e}")


if __name__ == "__main__":
    main()
