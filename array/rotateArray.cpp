#include <algorithm>
#include <iostream>
#include <vector>

void rotate(std::vector<int> &nums, int k) {
  int n = nums.size();
  if (k > n)
    k = k % n;
  std::reverse(nums.begin(), nums.end());
  std::reverse(nums.begin(), nums.begin() + k);
  std::reverse(nums.begin() + k, nums.end());
}

int main() { return 0; }