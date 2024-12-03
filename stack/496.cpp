#include "./monotonicStack.h"
#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  std::vector<int> nextGreaterElement(std::vector<int> &nums1,
                                      std::vector<int> &nums2) {
    int n = nums1.size();
    std::vector<int> son(n);
    for (int i = 0; i < n; ++i) {
      auto it = std::find(nums2.begin(), nums2.end(), nums1[i]);
      bool found = false;
      for (auto j = it + 1; j != nums2.end(); ++j) {
        if (*j > nums1[i]) {
          son[i] = *j;
          found = true;
          break;
        }
      }
      if (!found)
        son[i] = -1;
    }
    return son;
  }
};

int main() {
  std::vector<int> nums = {7, 2, 8, 1, 2, 9, 3, 2};
  monotonicStack m;

  for (int i : nums)
    m.insert(i);

  while (!m.empty()) {
    std::cout << m.top() << " ";
    m.pop();
  }

  return 0;
}