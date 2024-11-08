#include <iostream>
#include <vector>

void merge(std::vector<int> &nums, int low, int mid, int high) {
    std::vector<int> temp;
    // storing  low and high in different var
    int left = low; 
    int right = mid + 1;
    // iterating while the left is lower then mid and right is lower then high
    while (left <= mid && right <= high) {
        if(nums[left] <= nums[right]) {
            temp.push_back(nums[left]);
            left++;
        } else {
            temp.push_back(nums[right]);
            right++;
        }
    }
    while (left <= mid) {
        temp.push_back(nums[left]);
        left++;
    }
    while (right <= high) {
        temp.push_back(nums[right]);
        right++;
    }

    // change the nums array for low to high index
    for (int i = low; i <= high; i++) {
        nums[i] = temp[i - low];
    }
    
}

void mS(std::vector<int> &nums, int low, int high) {
    if (low >= high) return;
    int mid = (low + high) / 2; // getting the mid
    mS(nums, low, mid); // calling for left sub half
    mS(nums, mid+1, high); // calling for right sub half
    merge(nums, low, mid, high); // calling merge
}

void mergeSort(std::vector<int> &nums) {
    mS(nums, 0, nums.size() - 1);
}


/*
Intuition:
    1. Divide the array into smaller subarrays until you have individual 
    elements (divide & conquer)
    
    2. Merge these sorted smaller subarrays back together by comparing 
    elements and placing them in correct order
    
    3. Think of it like sorting two already-sorted piles of cards by 
    comparing the top cards and placing the smaller one first
*/
int main() {
    std::vector<int> nums;
    int elem;
    std::cout << "Enter size of array: ";
    std::cin >> elem;
    std::cout << "\nEnter elements in array: ";
    for (int i = 0; i < elem; i++) {
        int temp;
        std::cin >> temp;
        nums.push_back(temp);
    }

    mergeSort(nums);
    std::cout << "\nSorted array: ";
    for(int i: nums) {
        std::cout << i << " ";
    }
    std::cout<<std::endl;
    return 0;

}