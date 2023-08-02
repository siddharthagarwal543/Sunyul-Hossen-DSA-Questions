//https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
class Solution{   
public:
    int t[101][10001];
    bool help(int sum,int idx,vector<int>&nums){
        if(sum==0)
        return true;
        if(idx==nums.size())
        return false;
        if(t[idx][sum]!=-1)
        return t[idx][sum];
        bool ans=help(sum,idx+1,nums);
        if(sum>=nums[idx])
        ans=ans|help(sum-nums[idx],idx+1,nums);
        return t[idx][sum]= ans;
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here
        int total=0,n=arr.size();
        for(auto it:arr)
        total+=it;
        int t[n+1][sum+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=sum;j++){
                if(i==0)
                t[i][j]=0;
                if(j==0)
                t[i][j]=1;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                t[i][j]=t[i-1][j];
                if(arr[i-1]<=j)
                {
                    t[i][j]=max(t[i][j],t[i-1][j-arr[i-1]]);
                }
            }
        }
        return t[n][sum];
    }
};