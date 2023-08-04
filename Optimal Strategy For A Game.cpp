//https://practice.geeksforgeeks.org/problems/optimal-strategy-for-a-game-1587115620/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
class Solution{
    public:
    int t[1001][1001];
    long long help(int arr[],int start,int end){
        if(start==end)
        return arr[start];
        if(end-start==1)
        return max(arr[start],arr[start+1]);
        if(t[start][end]!=-1)
        return t[start][end];
        return t[start][end]=max(arr[start]+min(help(arr,start+1,end-1),help(arr,start+2,end)),arr[end]+min(help(arr,start+1,end-1),help(arr,start,end-2)));

    }
    long long maximumAmount(int arr[], int n){
        // Your code here
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                t[i][j]=-1;
            }
        }
        return help(arr,0,n-1);
    }
};