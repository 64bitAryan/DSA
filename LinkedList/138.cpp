// Deep copy an linked list with random pointers.
#include <iostream>

class Node {
public:
  int val;
  Node *next;
  Node *random;

  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

// 1. Insert copy Node in btwn
// 2. Connecting random pointers.
// 3. Connecting the next pointers.

Node *copyRandomList(Node *head) {
  Node *curr = head;
  while (curr) {
    Node *new_node = new Node(curr->val);
    new_node->next = curr->next;
    curr->next = new_node->next;
    curr = new_node->next;
  }
  curr = head;
  while (curr) {
    if (curr) {
      curr->next->random = curr->random->next;
    }
    curr = curr->next->next;
  }

  Node *old_head = head;
  Node *new_head = old_head->next;
  Node *old_curr = old_head;
  Node *new_cur = new_head;

  while (old_curr) {
    // break the bond btwn the intermediate node
    // connect it to the original next;
    old_curr->next = old_curr->next->next;

    new_cur->next = new_cur->next ? new_cur->next->next : nullptr;
    old_curr = old_curr->next;
    new_cur = new_cur->next;
  }

  return new_head;
}

int main() { return 0; }