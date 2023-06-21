//Problem link:https://practice.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1
class Solution// TC O(N) SC O(1) By Counting number of 0's,1's and 2's
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        int one=0,zero=0,two=0;
        Node*temp=head;
        while(temp){
            if(temp->data==0)
            zero++;
            else if(temp->data==1)
            one++;
            else
            two++;
            temp=temp->next;
        }
        temp=head;
        while(zero){
            temp->data=0;
            temp=temp->next;
            zero--;
        }
        while(one){
            temp->data=1;
            temp=temp->next;
            one--;
        }
        while(two){
            temp->data=2;
            temp=temp->next;
            two--;
        }
        return head;
        // Add code here
        
    }
};