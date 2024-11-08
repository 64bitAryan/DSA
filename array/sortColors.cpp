#include <iostream>
#include <vector>
#include <algorithm>

void sortColors(std::vector<int>& nums) {
    int left = 0;
    int mid = 0;
    int right = nums.size() - 1;

    while (mid <= right) {
        switch (nums[mid]) {
        case 0:
            std::swap(nums[left++], nums[mid++]);
            break;

        case 1:
            mid++;
            break;

        case 2:
            std::swap(nums[right--], nums[mid]);
            break;
        }
    }
}

int main() {
    std::vector v1 {2,0,2,1,1,0};
    std::vector v2 {2,0,1};

    return 0;
}