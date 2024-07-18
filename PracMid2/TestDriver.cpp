#include "BST.h"
#include <cstdlib>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::nothrow;
using std::vector;

int main() {
  cout << "hello" << endl;
  vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  BST *bst = new BST();
  BST *bst2 = new BST();
  for (auto x : vec) {
    bst2->insert(x);
  }
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
  cout << "hieght of bst2: should be 9" << bst2->height() << endl;

  return EXIT_SUCCESS;
}
