//Problem link:

class Solution//TC O(N) SC O(1) iterate and delete last node
{
    public:
    //Function to delete a node without any reference to head pointer.
    void deleteNode(Node *del)
    {
       // Your code here
       Node*curr=del;
       while(curr->next->next!=NULL)
       {
           curr->data=curr->next->data;
           curr=curr->next;
       }
       Node*temp=curr->next;
       curr->data=temp->data;
       curr->next=NULL;
       delete temp;
    }

};

class Solution// TC O(1) SC O(1) just update current pointer as next pointer
{
    public:
    //Function to delete a node without any reference to head pointer.
    void deleteNode(Node *del)
    {
       // Your code here
       Node* next=del->next;
       del->data=next->data;
        delete(del->next);
       del->next=next->next;
       return ;
       
    }

};