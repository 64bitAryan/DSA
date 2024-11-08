#include <iostream>
#include <vector>

int majorityElement(std::vector<int> &nums) {
  int count = 0;
  int elem = 0;
  for (int i = 0; i < nums.size(); i++) {
    if (count == 0) {
      elem = nums[i];
    }
    if (nums[i] == elem) {
      count++;
    } else {
      count--;
    }
  }
  return elem;
}

int main() {
  std::vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
  int res = majorityElement(nums);

  return 0;
}