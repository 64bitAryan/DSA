#include <iostream>
#include <vector>

int singleNumber(std::vector<int> &nums) {
  int temp = 0;
  for (int i : nums) {
    temp ^= i;
  }
  return temp;
}

int main() { return 0; }