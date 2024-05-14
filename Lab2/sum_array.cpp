#include <iostream>

using std::cin;
using std::cout;

int sumArray(int arr[], unsigned int size) {
  int sum = 0;
  for (int i = 0; i < size; i++) {
    sum += arr[i];
  }
  return sum;
}
int main() {
  int *arr = nullptr;
  unsigned int size;
  int value;
  cout << "insert size of array";
  cin >> size;
  arr = new int[size];
  for (int i = 0; i < size; i++) {
    cout << "insert value of array at index " << i;
    cin >> value;
    arr[i] = value;
  }
  delete[] arr;

  return sumArray(arr, size);
}
