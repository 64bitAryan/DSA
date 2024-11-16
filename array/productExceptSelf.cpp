#include <iostream>
#include <vector>

/*
e.g
    [1,2,3,4]
    <--------
    [24,12,4,6]
    --------->
    [24,12,8,6]
 */

std::vector<int> productExceptSelf(std::vector<int> &nums) {
  std::vector<int> res(nums.size(), 0);
  if (nums.size() == 1 || nums.size() == 0)
    return nums;
  res[nums.size() - 1] = 1;
  int prod = 1;
  // iterate from the end and store the product of all elements to the right
  for (int i = nums.size() - 1; i > 0; i--) {
    res[i - 1] = res[i] * nums[i];
  }
  // iterate from the beginning and multiply the product of all elements to the
  // left to itself
  for (int i = 0; i < nums.size() - 1; i++) {
    prod *= nums[i];
    res[i + 1] = prod * res[i + 1];
  }
  return res;
}

std::vector<int> productExceptSelfWithDiv(std::vector<int> &nums) {
  int prod = 1;
  for (int i : nums) {
    prod *= i;
  }
  for (int i = 0; i < nums.size(); i++) {
    nums[i] = prod / nums[i];
  }
  return nums;
}

int main() {
  std::vector<int> v = {1, 2, 3, 4};
  std::vector<int> res = productExceptSelf(v);
  for (int i : res) {
    std::cout << i << " ";
  }
  return 0;
}