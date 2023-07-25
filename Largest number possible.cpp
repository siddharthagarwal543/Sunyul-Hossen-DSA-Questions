//Problem link:https://practice.geeksforgeeks.org/problems/largest-number-possible5028/1
class Solution{
public:
    
    string findLargest(int N, int S){
        // code here
        if(S==0&&N>1||S>N*9)
        return "-1";
        string ans="";
        for(int i=0;i<N;i++)
        {
            if(S>=9){
                S-=9;
                ans+="9";
            }
            else{
                ans+=to_string(S);
                S=0;
            }
        }
        return ans;
    }
};