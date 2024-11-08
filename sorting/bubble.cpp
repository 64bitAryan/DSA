#include<iostream>
#include<vector>

void bubbleSort(std::vector<int> &nums) {
    for (int i = 0; i < nums.size() - 1; i++) {
        for (int j = 0; j < nums.size() - i - 1; j++) {
            if (nums[j] > nums[j+1]){
                int temp = nums[j+1];
                nums[j + 1] = nums[j];
                nums[j] = temp;
            }
        }
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

    bubbleSort(nums);

    for(int i: nums) {
        std::cout << i << " ";
    }
    std::cout<<std::endl;
    return 0;

}