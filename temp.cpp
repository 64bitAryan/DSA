#include <iostream>
#include <vector>

int main() {

  std::vector<int> t(3);
  t[0] = 1;
  t[1] = 2;
  t[2] = 3;

  t.insert(t.begin(), 2);
  t.pop_back();

  for (auto i : t) {
    std::cout << i;
  }

  std::cout << "\n" << t.size() << "\n";

  return 0;
}
// find . -type f -name "*.cpp" | wc -l