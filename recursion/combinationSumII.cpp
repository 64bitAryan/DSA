#include <algorithm>
#include <iostream>
#include <vector>

void getCombinationSum(int index, std::vector<std::vector<int>> &res,
                       std::vector<int> &nums, std::vector<int> &temp,
                       int target) {
  if (target == 0) {
    res.push_back(temp);
    return;
  }
  for (int i = index; i < nums.size(); i++) {
    if (i > index && nums[i] == nums[i - 1])
      continue;
    if (nums[i] > target)
      break;
    temp.push_back(nums[i]);
    getCombinationSum(i + 1, res, nums, temp, target - nums[i]);
    temp.pop_back();
  }
}
std::vector<std::vector<int>> combinationSum2(std::vector<int> &candidates,
                                              int target) {
  std::sort(candidates.begin(), candidates.end());
  std::vector<std::vector<int>> res;
  std::vector<int> temp;
  getCombinationSum(0, res, candidates, temp, target);
  return res;
}
int main() {
  std::vector<int> c = {10, 1, 2, 7, 6, 1, 5};
  int target = 8;
  std::vector<std::vector<int>> res = combinationSum2(c, target);
  for (auto i : res) {
    for (int j : i) {
      std::cout << j << " " << std::endl;
    }
    std::cout << std::endl;
  }
  return 0;
}