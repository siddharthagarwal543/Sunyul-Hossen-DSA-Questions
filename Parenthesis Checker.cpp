//Problem link:https://leetcode.com/problems/valid-parentheses/
class Solution {//TC O(N) SC O(N)
public:
    bool isValid(string s) {
       stack<char>st;
       for(int i=0;i<s.length();i++){
           if(s[i]=='('||s[i]=='{'||s[i]=='[')//store opening brackets in stack
           st.push(s[i]);
           else if(s[i]==')'||s[i]=='}'||s[i]==']')
           {
               if(st.empty())//we encounter closing bracket as first element, never form valid parenthisis
               return false;
               char temp=st.top();
               st.pop();
               if(temp=='('&&s[i]==')')//checking all valid pairs
               continue;
               else if(temp=='['&&s[i]==']')
               continue;
               else if(temp=='{'&&s[i]=='}')
               continue;
               else//no valid pair formed
               return false;
           }
           cout<<i<<" ";
       } 
       return st.empty();
    }
};