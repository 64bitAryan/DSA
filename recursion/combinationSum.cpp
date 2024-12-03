#include <iostream>
#include <vector>

void getCombinationSum(std::vector<std::vector<int>> &res,
                       std::vector<int> &nums, std::vector<int> &store,
                       int index, int sum, int size) {
  if (index == size) {
    if (sum == 0) {
      res.push_back(store);
    }
    return;
  }
  if (nums[index] <= sum) {
    // tasking the element
    store.push_back(nums[index]);
    getCombinationSum(res, nums, store, index, sum - nums[index], size);

    // getting rid of the element (not taking the element)
    store.pop_back();
  }
  getCombinationSum(res, nums, store, index + 1, sum, size);
}

std::vector<std::vector<int>> combinationSum(std::vector<int> &candidates,
                                             int target) {
  std::vector<std::vector<int>> res;
  std::vector<int> store;

  getCombinationSum(res, candidates, store, 0, target, candidates.size());
  return res;
}

int main() { return 0; }