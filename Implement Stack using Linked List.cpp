//Problem link:https://practice.geeksforgeeks.org/problems/implement-queue-using-linked-list/1
void MyQueue:: push(int x)
{
    if(front==NULL){//If queue is empty
        front=new QueueNode(x);
        rear=front;
    }
    else{
        rear->next=new QueueNode(x);
        rear=rear->next;
    }
        // Your Code
}

//Function to pop front element from the queue.
int MyQueue :: pop()
{
    if(front==NULL)//If queue is empty
    return -1;
    QueueNode* tempNode=front;//the starting node should be deleted to free space
    int data=tempNode->data;
    front=front->next;
    delete tempNode;
    return data;
        // Your Code       
}