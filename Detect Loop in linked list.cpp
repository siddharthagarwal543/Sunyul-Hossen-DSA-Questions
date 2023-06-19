//Problem link:https://leetcode.com/problems/linked-list-cycle/
class Solution {// TC O(N) SC O(N) using map
public://we will continue iterating list till we don't get second occurence of a node
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*,int>mp;
        ListNode*slow=head;
        while(slow!=NULL){
            mp[slow]++;
            if(mp[slow]==2)
            return true;
            slow=slow->next;
        }
        return false;
        
    }
};

class Solution {// TC O(N) SC O(1) floyd's cycle detection algorithm
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL||head->next==NULL||head->next->next==NULL)
        return false;
        ListNode *slow=head->next,*fast=head->next->next;
        while(slow!=NULL&&fast!=NULL){
            if(slow==fast)
            return true;
            if(slow->next==NULL||fast->next==NULL||fast->next->next==NULL)
            return false;
            slow=slow->next;
            fast=fast->next->next;
        }
        return false;
    }
};

//Similar Problem : https://www.interviewbit.com/problems/list-cycle/

/*
How do you detect a loop in a linked list?
A loop can be detected efficiently using the fast and slow pointer algorithm, where the fast pointer moves by two nodes and the slow pointer move by one node at a time.

Will the fast and slow pointer always meet at some point if the list contains a cycle?
Yes, if the linked list contains a cycle, the fast and slow pointer will always meet at some point.
*/