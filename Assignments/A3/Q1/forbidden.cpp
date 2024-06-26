// old deepcopy
void BST::deepCopyR(BSTNode *thisCurrent, BSTNode *rhsCurrent) {
  // Pointers to new BSTNodes for left and right children of current BSTNode
  BSTNode *insertLeft = nullptr;
  BSTNode *insertRight = nullptr;

  // Copy left child of rhs BST to current BST, if it exists
  if (rhsCurrent->hasLeft()) {
    insertLeft = new (nothrow) BSTNode(rhsCurrent->left->element);
  }

  // Copy right child of rhs BST to current BST, if it exists
  if (rhsCurrent->hasRight()) {
    insertRight = new (nothrow) BSTNode(rhsCurrent->right->element);
  }

  // Update left and right child pointers of current node
  thisCurrent->left = insertLeft;
  thisCurrent->right = insertRight;

  // Recursively copy the left subtree, if it exists
  if (thisCurrent->hasLeft()) {
    deepCopyR(thisCurrent->left, rhsCurrent->left);
  }

  // Recursively copy right subtree, if it exists
  if (thisCurrent->hasRight()) {
    deepCopyR(thisCurrent->right, rhsCurrent->right);
  }
}

// old search
// If the current BSTNode is not null, continue searching
if (current != nullptr) {
  // If the current BSTNode contains the targetElement, return its element
  if (current->element == targetElement) {
    return current->element;
  }
  // If the targetElement is greater than current BSTNode's element, search
  // right subtree
  if (targetElement > current->element) {
    return retrieveR(targetElement, current->left);
  }
  // If the targetElement is greater than current BSTNode's element, search left
  // subtree
  if (targetElement < current->element) {
    return retrieveR(targetElement, current->right);
  }
}
// If the element is not found, throw an exception
throw ElementDoesNotExistException("Element does not exist");
