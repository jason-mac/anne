import sys

from bst import BST
from helper import bst_sort, bst_to_array, merge_sort, print_BST_node


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
        "Input an output file name (Press enter for default value of 'output.txt'): "
    )
    if write_file_name == "":
        write_file_name = "output.txt"
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
