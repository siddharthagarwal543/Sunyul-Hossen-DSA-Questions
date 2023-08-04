//https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
class Solution{

  public:
  
    int help(vector<vector<int>>&t,int idx,int nums[],int n,int s1,int s2)
    {
        if(idx==n)
        return abs(s1-s2);
        if(t[idx][s1]!=-1)
        return t[idx][s1];
        int a =help(t,idx+1,nums,n,s1,s2);
        int b=help(t,idx+1,nums,n,s1+nums[idx],s2-nums[idx]);
     //   cout<<a<<" "<<b<<endl;
        return t[idx][s1]=min(a,b);
    }
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum=0;
	    for(int i=0;i<n;i++)
	    sum+=arr[i];
	    vector<vector<int>>t(n,vector<int>(sum,-1));
	    return help(t,0,arr,n,0,sum);
	} 
};