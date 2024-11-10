#include <iostream>
#include <vector>

std::vector<int> replaceElements(std::vector<int> &arr) {
  int n = arr.size();
  if (n == 1) {
    arr[n - 1] = -1;
    return arr;
  }
  int maxVal = arr[n - 1];
  arr[n - 1] = -1;
  for (int i = n - 2; i >= 0; i--) {
    if (arr[i] > maxVal) {
      std::swap(maxVal, arr[i]);
    } else {
      arr[i] = maxVal;
    }
  }
  return arr;
}
int main() { return 0; }