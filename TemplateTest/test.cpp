#include "Node.h"
#include <cstdlib>
#include <iostream>

using std::cout;
using std::endl;
using std::nothrow;

int main() {
  int v1 = 1;
  int v2 = 2;
  int v3 = 3;
  Node<int> *n1 = new Node<int>(v1);
  cout << n1->getData() << endl;
  return EXIT_SUCCESS;
}
