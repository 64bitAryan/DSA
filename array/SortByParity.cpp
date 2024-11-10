#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> sortArrayByParity(std::vector<int> &nums) {
  int t = 0;
  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] % 2 == 0) {
      std::swap(nums[i], nums[t]);
      ++t;
    }
  }
  return nums;
}

int main() { return 0; }