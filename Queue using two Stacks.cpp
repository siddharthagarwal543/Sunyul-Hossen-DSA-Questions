//Problem link:https://practice.geeksforgeeks.org/problems/queue-using-stack/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
class Queue {// TC O(N) SC O(N) make either enqueue costly or dequeue costly
    stack<int> input, output;
public:

    void enqueue(int x) {
        input.push(x);
    }

    int dequeue() {
        int temp=-1;
        while(!input.empty()){
            temp=input.top();
            input.pop();
            if(input.empty())
            continue;
            output.push(temp);
        }
        while(!output.empty()){
            input.push(output.top());
            output.pop();
        }
        return temp;
    }