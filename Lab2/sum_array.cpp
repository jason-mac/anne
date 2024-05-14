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
  int size;
  int value;
  cout << "insert size of array";
  cin >> value;
  for (int i = 0; i < size; i++) {
    cout << "insert value of array at index " << i;
    cin >> value;
    arr[i] = value;
  }
  delete[] arr;

  return sumArray(arr, size);
}
