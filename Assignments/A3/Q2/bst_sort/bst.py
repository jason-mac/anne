"""
This module is a bst class
"""


class BST:
    def __init__(self):
        self.root = None

    def insert(self, val):
        if self.root is None:
            self.root = BSTNode(val)
            return
        self.insertR(self.root, val)

    def is_balanced(self):
        result = self.is_balanced_rec(self.root)
        return result

    def is_balanced_rec(self, current):
        if current is None:
            return 0
        left_height = self.is_balanced_rec(current.left)
        right_height = self.is_balanced_rec(current.right)
        if abs(left_height - left_height) > 2:
            return False
        return max(left_height, right_height) + 1

    def insertR(self, current_node, val):
        if current_node.val == val:
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
        """
        function
        """
        if current is None:
            return
        visit(current)
        self.pre_order_traversal(current.left, visit)
        self.pre_order_traversal(current.right, visit)


class BSTNode:
    """
    i do not care
    """

    def __init__(self, val):
        """
        do not care
        """
        self.val = val
        self.left = None
        self.right = None

    def has_left(self):
        """
        still do not care
        """
        if self.left is None:
            return False
        return True

    def has_right(self):
        """
        lmfao
        """
        if self.right is None:
            return False
        return True
