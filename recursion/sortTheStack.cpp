#include <deque>
#include <iostream>
#include <stack>

void insert(std::stack<int> &s, int val) {
  if (s.empty() || s.top() >= val) {
    s.push(val);
    return;
  }
  int temp = s.top();
  s.pop();
  insert(s, val);
  s.push(temp);
  return;
}
void sortStack(std::stack<int> &s) {
  if (s.empty())
    return;
  int temp = s.top();
  s.pop();
  sortStack(s);
  insert(s, temp);
  return;
}

int main() {
  std::deque<int> d = {4, 3, 6, 8, 1, 19, 44, 3, 33};
  std::stack<int> s(d);

  sortStack(s);

  while (!s.empty()) {
    std::cout << s.top() << " ";
    s.pop();
  }

  return 0;
}