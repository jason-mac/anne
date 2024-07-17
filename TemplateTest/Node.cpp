/* QUESTION
 * Include in cpp file or not include?
 */
#include "Node.h"

template <class T> Node<T>::Node() {}
template <class T> Node<T>::Node(T &data) { this->data = data; }
template <class T> T &Node<T>::getData() const { return this->data; }
