#include <iostream>
#include <vector>
#include <algorithm>

int quick(std::vector<int> &nums, int low, int high) {
    int pivot = low;
    int left = low;
    int right = high;
    while(left < right) {
        while (nums[left] <= nums[pivot] && left <= high) {
            left++;
        }
        while (nums[right] > nums[pivot] && right >= low) {
            right--;
        }
        if(left < right)
        std::swap(nums[left], nums[right]);
    }

    std::swap(nums[low], nums[right]);
    return right;
}

void qS(std::vector<int> &nums, int low, int high) {
    if(low < high) {
        int midIndex = quick(nums, low, high);
        qS(nums, low, midIndex - 1);
        qS(nums, midIndex + 1, high);
    }
}

void quickSort(std::vector<int> &nums) {
    qS(nums, 0, nums.size() - 1);
}

int main() {
    std::vector<int> nums = {3, 6, 1, 5, 8, 9, 5, 4, 78, 34, 99, 32, 41, 57};

    quickSort(nums);
    std::cout << "\nSorted array: ";
    for(int i: nums) {
        std::cout << i << " ";
    }
    std::cout<<std::endl;
    return 0;

}