#include <iostream>
#include <stack>
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Approach 1
bool isPalindrome(ListNode *head) {
  std::stack<int> st;
  ListNode *slow = head;
  ListNode *fast = head;

  if (head->next == nullptr)
    return true;

  while (fast && fast->next) {
    st.push(slow->val);
    slow = slow->next;
    fast = fast->next->next;
  }

  if (fast) {
    slow = slow->next;
  }

  while (slow) {
    if (slow->val != st.top())
      return false;
    slow = slow->next;
    st.pop();
  }
  return true;
}

// Approach 2
ListNode *reverseList(ListNode *head) {
  ListNode *nextPtr = nullptr;
  while (head != nullptr) {
    ListNode *ptr = head->next;
    head->next = nextPtr;
    nextPtr = head;
    head = ptr;
  }
  return nextPtr;
}

bool isPalindromeOpt(ListNode *head) {
  if (head == nullptr || head->next == nullptr)
    return true;

  ListNode *fast = head;
  ListNode *slow = head;

  while (fast->next && fast->next->next) {
    fast = fast->next->next;
    slow = slow->next;
  }

  slow->next = reverseList(slow->next);
  slow = slow->next;

  while (slow != nullptr) {
    if (head->val != slow->val)
      return false;
    head = head->next;
    slow = slow->next;
  }
  return true;
}

int main() { return 0; }