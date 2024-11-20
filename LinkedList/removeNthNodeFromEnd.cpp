#include <iostream>
#include <vector>
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *removeNthFromEnd(ListNode *head, int n) {
  ListNode *res = new ListNode();
  res->next = head;
  ListNode *ptr1 = res;
  ListNode *ptr2 = res;

  for (int i = 1; i <= n; i++) {
    ptr2 = ptr2->next;
  }
  while (ptr2->next) {
    ptr1 = ptr1->next;
    ptr2 = ptr2->next;
  }
  ptr1->next = ptr1->next->next;
  return res->next;
}

int main() { return 0; }