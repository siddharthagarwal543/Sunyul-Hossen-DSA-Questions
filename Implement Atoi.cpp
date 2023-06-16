//Problem link:https://leetcode.com/problems/string-to-integer-atoi/description/
class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        long long ans=0;
        long long mn=-2147483648,mx=2147483647;//for checking number is in range
        bool neg=false;
        while(i<s.length()&&s[i]==' ')//only blank space are allowed before number
        i++;
        if(s[i]=='-')
        {
            neg=true;
            i++;
        }
        else if(s[i]=='+')
        i++;//using else if bcoz there can be case like '-+21'
        while(i<s.length()&&(s[i]<='9'&&s[i]>='0')){
                ans=ans*10+(s[i]-'0');
                if(ans>mx){
            if(neg){
                ans=ans>=mx+1?mn:mn-1;
            }
            else
            ans=mx;
           return ans;
        }
            i++;
        }
        return neg==false?ans:ans*-1;
    }
};