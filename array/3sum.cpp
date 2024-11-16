#include <algorithm>
#include <iostream>
#include <vector>

std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {
  std::vector<std::vector<int>> res;
  int n = nums.size();
  sort(nums.begin(), nums.end());
  for (int i = 0; i < nums.size(); i++) {
    if (i > 0 && nums[i] == nums[i - 1]) {
      continue;
    }
    int reqSum = (-1 * nums[i]);
    int p1 = i + 1;
    int p2 = nums.size() - 1;
    while (p1 < p2) {
      int sum = nums[p1] + nums[p2];
      if (sum < reqSum) {
        p1++;
      } else if (sum > reqSum) {
        p2--;
      } else {
        res.push_back({nums[i], nums[p1], nums[p2]});
        while (p1 < p2 && nums[p1] == nums[p1 + 1])
          p1++;
        while (p1 < p2 && nums[p2] == nums[p2 - 1])
          p2--;
        p1++;
        p2--;
      }
    }
  }
  return res;
}

int main() {
  std::vector<int> v = {0, 0, 0, 0};
  std::vector<std::vector<int>> res = threeSum(v);
  for (std::vector<int> i : res) {
    for (int j : i) {
      std::cout << j << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}