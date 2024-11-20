#include <iostream>
#include <queue>

std::vector<int> maxSubsequence(std::vector<int> &nums, int k) {}

int main() {
  std::vector<int> nums = {2, 1, 3, 3};
  int k = 2;
  std::vector<int> res = maxSubsequence(nums, k);
  std::cout << std::endl;
  for (int i : res) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  return 0;
}