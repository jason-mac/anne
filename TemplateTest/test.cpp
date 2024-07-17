#include "Node.h"
#include <cstdlib>
#include <iostream>

using std::cout;
using std::endl;
using std::nothrow;

int main() {
  Node<int> *n1 = new Node<int>(1);
  cout << n1->getData() << endl;
  return EXIT_SUCCESS;
}
