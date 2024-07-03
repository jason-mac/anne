def array_to_bst_sort(input, bst, left, right):
    """
    bst_sort function, sorts an array for a mostly balaned bst tree sort
    """
    if left > right:
        return
    middle = (right + left) // 2
    bst.insert(input[middle])
    array_to_bst_sort(input, bst, left, middle - 1)
    array_to_bst_sort(input, bst, middle + 1, right)


def print_BST_node(current_node):
    print(current_node.val, end=" ")


def bst_to_array(current, arr):
    if current is None:
        return
    arr.append(current.val)
    bst_to_array(current.left, arr)
    bst_to_array(current.right, arr)


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
