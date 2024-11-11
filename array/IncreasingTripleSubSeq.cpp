#include <climits>
#include <iostream>
#include <vector>

bool increasingTriplet(std::vector<int> &nums) {
  int first = INT_MAX;
  int second = INT_MAX;
  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] <= first) {
      first = nums[i];
    } else if (nums[i] <= second) {
      second = nums[i];
    } else {
      return true;
    }
  }
  return false;
}

int main() { return 0; }