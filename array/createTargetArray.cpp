#include <iostream>
#include <vector>

std::vector<int> createTargetArray(std::vector<int> &nums,
                                   std::vector<int> &index) {
  std::vector<int> res(nums.size(), -1);
  for (int i = 0; i < nums.size(); i++) {
    if (res[index[i]] == -1)
      res[index[i]] = nums[i];
    else {
      int itr = index[i] + 1;
      int temp = res[index[i]];
      while (itr < nums.size() && res[itr] != -1) {
        std::swap(temp, res[itr]);
        itr++;
      }
      if (itr < nums.size()) {
        res[itr] = temp;
        res[index[i]] = nums[i];
      }
    }
  }
  return res;
}

std::vector<int> createTargetArrayOpt(std::vector<int> &nums,
                                      std::vector<int> &index) {
  std::vector<int> res;
  for (int i = 0; i < nums.size(); i++) {
    res.insert(res.begin() + index[i], nums[i]);
  }
  return res;
}

int main() {
  std::vector<int> v = {1, 2, 3, 4, 0, 5, 6};
  std::vector<int> i = {0, 1, 2, 3, 3, 1, 0};
  std::vector<int> res = createTargetArray(v, i);
  for (int i : res) {
    std::cout << i << " ";
  }
  std::cout << "\n";
  return 0;
}