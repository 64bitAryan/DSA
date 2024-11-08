#include <iostream>
#include <vector>

void insertionSort(std::vector<int> &nums) {
    for(int i = 1;  i < nums.size(); i++) {
        int curr = nums[i];
        int j = i - 1;
        while (j >= 0 && nums[j] > curr){
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = curr;
    }
}

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

    insertionSort(nums);

    for(int i: nums) {
        std::cout << i << " ";
    } 
    return 0;

}