//Problem link:https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list

void hashAndRemove(Node * head) {
  unordered_map < Node * , int > node_map;
  Node * last = NULL;
  while (head != NULL) {
    if (node_map.find(head) == node_map.end()) {
      node_map[head]++;
      last = head;
      head = head -> next;
    } else {
      last -> next = NULL;
      break;
    }
  }
}

void removeCycle(Node * slow, Node * head) {
  for (Node * curr = head; curr != nullptr; curr = curr -> next) {
    Node * ptr = slow;
    while (ptr -> next != slow && ptr -> next != curr) {
      ptr = ptr -> next;
    }
    if (ptr -> next == curr) {
      ptr -> next = nullptr;
      return;
    }
  }
}
Node * identifyCycle(Node * head) {
  Node * slow = head, * fast = head;
 
  while (fast && fast -> next) {
    slow = slow -> next;
    fast = fast -> next -> next;
    if (slow == fast) {
      return slow;
    }
  }
  return nullptr;
}





/*
Q. How do you detect a loop in a linked list?
A. A loop can be detected efficiently using the fast and slow pointer algorithm, where the fast pointer moves by two nodes and the slow pointer move by one node at a time.

Q. Will the fast and slow pointer always meet at some point if the list contains a cycle?
A. Yes, if the linked list contains a cycle, the fast and slow pointer will always meet at some point.
*/