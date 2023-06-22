//Problem link:https://practice.geeksforgeeks.org/problems/stack-using-two-queues/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
void QueueStack :: push(int x)
{
    q1.push(x);
        // Your Code
}

//Function to pop an element from stack using two queues. 
int QueueStack :: pop()
{
       int temp=-1;
       while(!q1.empty()){
           temp=q1.front();
           q1.pop();
           if(q1.empty())
           continue;
           q2.push(temp);
       }
       while(!q2.empty()){
           q1.push(q2.front());
           q2.pop();
       }
       return temp;
        // Your Code       
}
