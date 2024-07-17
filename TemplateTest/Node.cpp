/* QUESTION
 * Include in cpp file or not include?
 */
#include "Node.h"

template <class T> Node<T>::Node(T &theData) {
  this->data = theData;
  this->next = nullptr;
}
template <class T> T &Node<T>::getData() const { return this->data; }
