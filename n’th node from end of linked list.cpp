//Problem link:https://leetcode.com/problems/remove-nth-node-from-end-of-list/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       if(head==NULL)
      return NULL;
      ListNode* fast=head,*slow=head;
      while(n--&&fast!=NULL){
          fast=fast->next;
      }
      if(fast==NULL)
      return slow->next;
      while(fast->next!=NULL){
          fast=fast->next;
          slow=slow->next;
      }
      if(slow->next!=NULL)
      slow->next=slow->next->next;
      return head;
    }
};