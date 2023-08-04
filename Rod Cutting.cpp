//https://practice.geeksforgeeks.org/problems/rod-cutting0840/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
class Solution{
  public:
  int t[1001][1001];
    int help(int len,int n,int idx,int prices[]){
        if(len==0)
        return 0;
        if(idx==n||len<0)
        return INT_MIN;
        if(t[idx][len]!=-1)
        return t[idx][len];
        int pick=help(len-idx-1,n,idx,prices)+prices[idx];
        int notPick=help(len,n,idx+1,prices);
        return t[idx][len]=max(pick,notPick);
    }
    int cutRod(int price[], int n) {
        //code here
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++)
            t[i][j]=-1;
        }
        return help(n,n,0,price);
    }
};