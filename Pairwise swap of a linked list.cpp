//Problem link: https://leetcode.com/problems/swap-nodes-in-pairs/
class Solution {//TC O(N) SC O(1)
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head||!head->next)
        return head;
        ListNode* dummyNode = new ListNode();
        ListNode* prevNode=dummyNode;
        ListNode* currNode=head;
        
        while(currNode && currNode->next){
            prevNode->next = currNode->next;
            currNode->next = prevNode->next->next;
            prevNode->next->next = currNode;
            
            prevNode = currNode;
            currNode = currNode->next;
        }
        head=dummyNode->next;
        delete dummyNode;
        return head;
    }
};