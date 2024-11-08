#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> smallerNumbersThanCurrent(std::vector<int> &nums) {
  std::vector<int> arr(101, 0);
  std::vector<int> res;

  for (int i : nums) {
    arr[i] += 1;
  }

  int sum = 0;
  int curr = 0;
  for (int i = 0; i < arr.size(); i++) {
    curr = arr[i];
    arr[i] = sum;
    sum += curr;
  }
  for (int i : nums) {
    res.push_back(arr[i]);
  }
  return res;
}

int main() {
  std::vector<int> v = {8, 1, 2, 2, 3};
  std::vector<int> res = smallerNumbersThanCurrent(v);

  std::cout << std::endl;
  for (int i : res) {
    std::cout << i << " ";
  }

  std::cout << std::endl;
  return 0;
}