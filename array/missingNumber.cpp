#include <iostream>
#include <vector>

int missingNumber(std::vector<int> nums) {
    int res = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        res ^= nums[i];
    }

    for (int i = 0; i <= nums.size(); i++) {
        res ^= i;
    }

    return res;
}

int main() {
    std::vector<int> nums = {9,6,4,2,3,5,7,0,1};
    int ans = missingNumber(nums);
    std::cout << "missing number is: " << ans << std::endl; 
    return 0;
}