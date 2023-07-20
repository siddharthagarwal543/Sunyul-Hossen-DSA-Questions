//Problem link:https://practice.geeksforgeeks.org/problems/find-optimum-operation4504/1
class Solution
{
  public:
  int t[100000];
    int help(int curr,int n){
        if(curr>n)
        return INT_MAX;
        if(t[curr]!=-1)
        return t[curr];
        if(curr==n)
        return t[curr]=0;
        return t[curr]=min(help(curr*2,n),help(curr+1,n))+1;
    }
    int minOperation(int n)
    {
        //code here.
        for(int i=0;i<=n;i++)
        t[i]=-1;
        return help(1,n)+1;
        
    }
};