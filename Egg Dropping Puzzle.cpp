//https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle-1587115620/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int t[201][201];
    int help(int n,int k)
    {
        if(k==0||k==1)
        return k;
        if(n==1)
        return k;
        if(t[n][k]!=-1)
        return t[n][k];
        int ans=INT_MAX;
        for(int i=1;i<=k;i++){
            int temp=max(help(n-1,i-1),help(n,k-i));
            ans=min(ans,temp);
        }
        return t[n][k]=ans+1;
    }
    int eggDrop(int n, int k) 
    {
        // your code here
        int ans=0;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=k;j++){
                t[i][j]=-1;
            }
        }
       return help(n,k);
    }
};
