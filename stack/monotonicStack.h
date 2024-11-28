#ifndef MONO_STACK
#define MONO_STACK

#include <stack>

class monotonicStack {
private:
  std::stack<int> s;
  std::stack<int> t;

public:
  void insert(int num) {
    if (s.empty()) {
      s.push(num);
    } else {
      while (!s.empty() && s.top() >= num) {
        t.push(s.top());
        s.pop();
      }
      s.push(num);
      while (!t.empty()) {
        s.push(t.top());
        t.pop();
      }
    }
  }
  int top() { return s.top(); }

  bool empty() { return s.empty(); }

  int size() { return s.size(); }

  void pop() { return s.pop(); }
};

#endif