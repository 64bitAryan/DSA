#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> twoSum(std::vector<int>& nums, int target) {
   std::unordered_map<int, int> m;
    std::vector<int> v;
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (m.count(complement)) {
            return {m[complement], i};
        }
        m[nums[i]] = i;
    }
    return v;
}

int main() {
    std::vector<int> v = {2,7,11,15};
    std::vector<int> res = twoSum(v, 9);
    std::cout << res[0] << ", " << res[1] << std::endl; 
    return 0;
}