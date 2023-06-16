//Problem link: https://leetcode.com/problems/middle-of-the-linked-list/description/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {//Tc O(N) SC O(1) using fast and slow pointers
        ListNode*slow=head,*fast=head;
        while(slow->next!=NULL&&fast->next!=NULL&&fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        if(fast->next!=NULL)//if the list is of even length
        slow=slow->next;
        return slow;
    }
};

//Similar question: https://www.interviewbit.com/problems/kth-node-from-middle/