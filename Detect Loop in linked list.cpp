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