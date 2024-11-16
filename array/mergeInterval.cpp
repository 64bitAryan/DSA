#include <algorithm>
#include <iostream>
#include <vector>
std::vector<std::vector<int>> merge(std::vector<std::vector<int>> &nums) {
  int i = 1;
  std::vector<std::vector<int>> res;

  std::sort(nums.begin(), nums.end());
  std::vector<int> temp = nums[0];

  while (i < nums.size()) {
    if (temp[1] >= nums[i][0]) {
      temp[1] = std::max(nums[i][1], temp[1]);
    } else {
      res.push_back(temp);
      temp = nums[i];
    }
    i++;
  }
  res.push_back(temp);
  return res;
}

int main() {
  std::vector<std::vector<int>> v = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
  std::vector<std::vector<int>> res = merge(v);
  for (std::vector<int> i : res) {
    std::cout << "[" << i[0] << ", " << i[1] << "] ";
  }

  return 0;
}