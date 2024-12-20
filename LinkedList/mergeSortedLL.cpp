#include <algorithm>
#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
  if (list1 == nullptr)
    return list2;
  if (list2 == nullptr)
    return list1;

  if (list1->val > list2->val)
    std::swap(list1, list2);

  ListNode *res = list1;
  while (list1 && list2) {
    ListNode *temp = nullptr;
    while (list1 && list1->val <= list2->val) {
      temp = list1;
      list1 = list1->next;
    }
    temp->next = list2;
    std::swap(list1, list2);
  }
  return res;
}

int main() { return 0; }