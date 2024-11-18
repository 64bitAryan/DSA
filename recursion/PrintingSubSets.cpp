#include <iostream>
#include <vector>

void getSubSet(int index, std::vector<std::vector<int>> &res,
               std::vector<int> &temp, std::vector<int> &nums) {
  // return if index is greater than or equal to the size of the array
  // that means we have reached the end of the array
  if (index >= nums.size()) {
    res.push_back(temp);
    return;
  }
  // take the element at the current index
  temp.push_back(nums[index]);
  // call the function again with the next index
  getSubSet(index + 1, res, temp, nums);
  // remove the element at the current index
  // this is done to backtrack and get all the subsets
  temp.pop_back();
  // call the function again with the next index
  getSubSet(index + 1, res, temp, nums);
}
std::vector<std::vector<int>> subsets(std::vector<int> &nums) {
  std::vector<std::vector<int>> res;
  std::vector<int> temp;
  getSubSet(0, res, temp, nums);
  return res;
}

int main() {
  std::vector<int> nums = {1, 2, 3};
  std::vector<std::vector<int>> res = subsets(nums);

  for (std::vector<int> i : res) {
    for (int j : i) {
      std::cout << j << " ";
    }
    std::cout << "\n";
  }

  return 0;
}