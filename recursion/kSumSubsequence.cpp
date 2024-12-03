/*
    With these question we are going to understand the patterns present in the
    recursion
*/
#include <iostream>
#include <vector>

// printing the single response
bool getKSum(std::vector<int> nums, std::vector<int> store, int index, int ts,
             int sum, int size, std::vector<std::vector<int>> &res) {
  if (index == size) {
    if (ts == sum) {
      res.push_back(store);
      return true;
    }
    return false;
  }

  ts += nums[index];
  store.push_back(nums[index]);
  if (getKSum(nums, store, index + 1, ts, sum, size, res))
    return true;

  ts -= nums[index];
  store.pop_back();

  if (getKSum(nums, store, index + 1, ts, sum, size, res))
    return true;
  return false;
}

// these gives all the possible results
void getKSum(int index, std::vector<int> nums, std::vector<int> store, int ts,
             int sum, int size, std::vector<std::vector<int>> &res) {
  if (index == size) {
    if (ts == sum) {
      res.push_back(store);
    }
    return;
  }

  ts += nums[index];
  store.push_back(nums[index]);
  getKSum(nums, store, index + 1, ts, sum, size, res);

  ts -= nums[index];
  store.pop_back();

  getKSum(nums, store, index + 1, ts, sum, size, res);
}

// these will return the count of the solution present
int getKSum(std::vector<int> nums, int index, int ts, int sum, int size) {
  if (index == size) {
    if (ts == sum)
      return 1;
    else
      return 0;
  }

  ts += nums[index];
  int count = getKSum(nums, index + 1, ts, sum, size);

  ts -= nums[index];

  int notCount = getKSum(nums, index + 1, ts, sum, size);
  return count + notCount;
}

int main() {
  std::vector<int> nums = {1, 2, 1};
  std::vector<int> store;
  std::vector<std::vector<int>> res;
  int sum = 2;
  int size = nums.size();
  int count = getKSum(nums, 0, 0, sum, size);

  std::cout << "Number of possible solution is: " << count << std::endl;

  return 0;
}