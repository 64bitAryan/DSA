#include <iostream>
#include <vector>

void insert(std::vector<int> &nums, int val) {
  int size = nums.size();
  if (nums.empty() || nums[size - 1] <= val) {
    nums.push_back(val);
    return;
  }
  int temp = nums[size - 1];
  nums.pop_back();

  insert(nums, val);

  nums.push_back(temp);
}
void sortArray(std::vector<int> &nums, int size) {
  if (size == 1)
    return;

  int temp = nums[size - 1];
  nums.pop_back();

  sortArray(nums, size - 1);

  insert(nums, temp);
  return;
}

int main() {
  std::vector<int> arr = {5, 3, 8, 6, 1, 2, 6};
  sortArray(arr, arr.size());
  for (auto i : arr) {
    std::cout << i << " ";
  }
  return 0;
}