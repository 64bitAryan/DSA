#include <iostream>
#include <vector>
#include <algorithm>

void selectionSort(std::vector<int> &nums) {
    for (int i = 0; i < nums.size() - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[j] < nums[min_index]){
                min_index = j;
            }
        }
        std::swap(nums[i], nums[min_index]);
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

    selectionSort(nums);

    for(int i: nums) {
        std::cout << i << " ";
    }
    std::cout<<std::endl;
    return 0;

}