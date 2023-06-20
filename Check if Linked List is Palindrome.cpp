//Problem link:https://leetcode.com/problems/reverse-linked-list/
class Solution {// TC O(N) SC O(1)
public:
    ListNode* reverseList(ListNode* head) {
        ListNode*temp=NULL;
        while(head!=NULL){
            ListNode*next=head->next;
            head->next=temp;
            temp=head;
            head=next;
        }
        return temp;
    }
};