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
