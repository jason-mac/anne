#include "Node.h"
#include <cstdlib>
#include <iostream>

using std::cout;
using std::endl;
using std::nothrow;

int main() {
  int testnumber = 0;
  Node<int> test(testnumber);
  cout << test.getData() << endl;
  /*
  int v1 = 1;
  int v2 = 2;
  int v3 = 3;
  Node<int> *n1 = new (nothrow) Node<int>(v1);
  Node<int> *n2 = new (nothrow) Node<int>(v2);
  Node<int> *n3 = new (nothrow) Node<int>(v3);
  n1->next = n2;
  n2->next = n3;
  cout << "n1->getData: " << n1->getData() << endl;
  cout << "n1->getData: " << n1->next->getData() << endl;
  */
  return EXIT_SUCCESS;
}
