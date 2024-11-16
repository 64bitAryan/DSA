#include <climits>
#include <iostream>
#include <vector>

int maxProfit(std::vector<int> &nums) {
  int min = INT_MAX;
  int profit = INT_MIN;
  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] < min) {
      min = nums[i];
    }
    if (nums[i] - min > profit) {
      profit = nums[i] - min;
    }
  }

  return profit;
}

int main() {
  std::vector<int> v = {7, 1, 5, 3, 6, 4};
  std::cout << maxProfit(v);
  return 0;
}