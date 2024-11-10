#include <iostream>
#include <vector>

int search(std::vector<int> &nums, int target) {
  int start = 0;
  int end = nums.size() - 1;
  while (start <= end) {
    int mid = (start + end) / 2;

    if (nums[mid] == target)
      return mid;

    // if the left part is sorted
    if (nums[mid] >= nums[start]) {
      // check if the element lies in the sorted part
      // if yes then ...
      if (target >= nums[start] && target < nums[mid]) {
        end = mid - 1;
        // if not then...
      } else {
        start = mid + 1;
      }
      // if the right part is sorted
    } else {
      // check if the element lies in the sorted part
      // if yes then ...
      if (target > nums[mid] && target <= nums[end]) {
        start = mid + 1;
        // if not then...
      } else {
        end = mid - 1;
      }
    }
  }
  return -1;
}

int main() { return 0; }