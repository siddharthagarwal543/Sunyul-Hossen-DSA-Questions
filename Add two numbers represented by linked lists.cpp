//Problem Link:https://leetcode.com/problems/add-two-numbers/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) { //TC O(N+M)
        if(l1==NULL&&l2==NULL)//If both list empty
        return NULL;
        if(l1==NULL)//if one of the list is empty return others
        return l2;
        if(l2==NULL)
        return l1;
        ListNode* res=new ListNode((l1->val+l2->val)%10);//initalize resultant linked list
        int rem=(l1->val+l2->val)/10;
        l1=l1->next;
        l2=l2->next;
        ListNode* head=res;
        while(l1!=NULL&&l2!=NULL){
            res->next=new ListNode((l1->val+l2->val+rem)%10);
            rem=(l1->val+l2->val+rem)/10;
            l1=l1->next;
            l2=l2->next;
            res=res->next;
        }
        while(l1!=NULL){// l1.len>l2.len
            res->next=new ListNode((l1->val+rem)%10);
            rem=(l1->val+rem)/10;
            res=res->next;
            l1=l1->next;
        }
         while(l2!=NULL){//l2.len>l1.len
            res->next=new ListNode((l2->val+rem)%10);
            rem=(l2->val+rem)/10;
            res=res->next;
            l2=l2->next;
        }
        if(rem)
        res->next=new ListNode(rem);
        return head;
    }
};

/*
Q. Why are zeros appended to the end of the smaller linked list?
Ans. Zeroes are appended to the end of the linked list which is equivalent to adding zeros before a number, the value the list represents doesn’t change, but the implementation becomes easier for the problem logic.

Q. How is the carry calculated for the sum of digits?
Ans. The carry is calculated for the sum of digits as “If the sum of digits exceeds 10, the carry is 1, else it is 0.”
*/