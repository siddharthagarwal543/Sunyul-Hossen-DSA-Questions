//Problem linK:https://leetcode.com/problems/intersection-of-two-linked-lists/description/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {//TC O(NlogN) SC o(N)
        unordered_map<ListNode*,int>mp;
        ListNode* temp=headA;
        while(temp!=NULL){
            mp[temp]++;
            temp=temp->next;
        }
        temp=headB;
        while(temp!=NULL){
            if(mp.find(temp)!=mp.end())
            return temp;
            temp=temp->next;
        }
        return NULL;
    }
};

class Solution {
public:
    int length(ListNode* head){
        int len=0;
        while(head){
            head=head->next;
            len++;
        }
        return len;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {//TC O(N) SCO(1)
       if(!headA||!headB)
       return NULL;
       int lnA=length(headA),lnB=length(headB);
       while(lnA>lnB){
           lnA--;
           headA=headA->next;
       }
       while(lnA<lnB){
           lnB--;
           headB=headB->next;
       }
       while(headA&&headB){
           if(headA==headB)
           return headA;
           headA=headA->next;
           headB=headB->next;
       }
       return NULL;
    }
};