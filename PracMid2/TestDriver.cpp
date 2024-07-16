#include "BST.h"
#include <cstdlib>
#include <iostream>

using std::cout;
using std::endl;
using std::nothrow;

int main() {
  cout << "hello" << endl;
  BST *bst = new BST();
  bst->insert(10);
  bst->insert(3);
  bst->insert(7);
  bst->insert(1);
  bst->insert(8);
  bst->insert(5); // Repeated insert
  bst->insert(4);
  bst->insert(6);
  bst->insert(2);
  bst->insert(5);
  cout << bst->numberOfNodes() << "number of noes" << endl;
  if (bst->getElementCount() == bst->numberOfNodes()) {
    cout << "get element count == number of nodes, good" << endl;
  }

  return EXIT_SUCCESS;
}
