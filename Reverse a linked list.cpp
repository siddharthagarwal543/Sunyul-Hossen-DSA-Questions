//Problem link: https://leetcode.com/problems/reverse-linked-list/
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
class Solution {// TC O(N) SC O(N) Using stack
public:
    ListNode* reverseList(ListNode* head) {
        stack<int>st;
        ListNode*temp=head;
        while(temp!=NULL){//pushing all the values in stack
            st.push(temp->val);
            temp=temp->next;
        }
        temp=head;
        while(temp!=NULL){//popping all the values from stack, stack follows FIFO
            temp->val=st.top();
            st.pop();
            temp=temp->next;
        }
        return head;
    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {//TC O(N) SC O(1)
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