//Problem Link:https://leetcode.com/problems/merge-two-sorted-lists/

class Solution {//Using ref pointer TC O(N+M) SC O(1)
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL&&list2==NULL)//if both list is empty, return NULL
        return NULL;
        if(list1==NULL)//if anyone list is empty, return another
        return list2;
        if(list2==NULL)
        return list1;
        ListNode* head=NULL;//assign head the lower value of both list head
        if(list1->val>list2->val)
       {
            head=new ListNode(list2->val);
            list2=list2->next;
       }
        else
        {
            head=new ListNode(list1->val);
            list1=list1->next;
        }
        ListNode* temp=head;
        while(list1!=NULL&&list2!=NULL){//add the node with lower value, increment the list with lower value and head
            if(list1->val>list2->val){
                temp->next=new ListNode(list2->val);
                list2=list2->next;
            }
            else{
                temp->next=new ListNode(list1->val);
                list1=list1->next;
            }
            temp=temp->next;
        }
        if(list1!=NULL){//if list1.len>list2.len
            temp->next=list1;
        }
        else if(list2!=NULL)//if list2.len>list1.len
            temp->next=list2;
        }
        return head;
    }
};

/*
we have discussed 4 different approaches to merge two sorted linked lists.

In Approach 1, we used simple recursion which took O(N) time complexity and O(N) auxiliary space.
In Approach 2, we used the dummy node method and returned the dummy.next pointer that took O(N) time complexity and O(1) auxiliary space.
In Approach 3, we used the local reference variable which took O(N) time complexity and O(1) auxiliary space.
In approach 4, we reverse the lists that took O(N) time complexity and O(1) auxiliary space.
*/