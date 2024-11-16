#include <iostream>
#include <vector>

/*
using pegion-hole principle to solve the problem

1. put all the negative numbers and numbers greater than n in the array to n+1
2. iterate through the array and mark the index of the number as negative
3. iterate through the array and return the first index which is positive

*/

int firstMissingPositive(std::vector<int> &nums) {
  int n = nums.size();
  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] <= 0 || nums[i] >= n + 1) {
      nums[i] = n + 1;
    }
  }

  for (int i = 0; i < nums.size(); i++) {
    int curr = abs(nums[i]);
    if (curr == n + 1)
      continue;
    if (nums[curr - 1] > 0) {
      nums[curr - 1] = -nums[curr - 1];
    }
  }

  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] > 0)
      return i + 1;
  }
  return n + 1;
}

int main() {
  std::vector<int> nums = {3, 4, -1, 1};
  int res = firstMissingPositive(nums);
  std::cout << res;
  return 0;
}