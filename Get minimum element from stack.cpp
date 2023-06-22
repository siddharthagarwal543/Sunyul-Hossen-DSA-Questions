//Problem link:https://leetcode.com/problems/min-stack/
class MinStack {//store in stack like {currEle,minEle}
public:
int mn=INT_MAX;
   stack<pair<int,int>>st;
    MinStack() {
     
        
    }
    
    void push(int val) {
        if(!st.size())
        st.push({val,val});
        else{
            if(st.top().second<val){
                st.push({val,st.top().second});
            }
            else{
                st.push({val,val});
            }
        }
    }
    
    void pop() {
        
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};
