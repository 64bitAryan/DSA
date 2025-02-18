#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {
  if (head == nullptr || head->next == nullptr)
    return false;
  ListNode *fast = head;
  ListNode *slow = head;

  while (fast->next && fast->next->next) {
    slow = slow->next;
    fast = fast->next->next;
    if (fast == slow)
      return true;
  }
  return false;
}
int main() { return 0; }