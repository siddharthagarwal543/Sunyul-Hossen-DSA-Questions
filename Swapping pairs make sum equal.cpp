//Problem link:https://practice.geeksforgeeks.org/problems/swapping-pairs-make-sum-equal4142/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
class Solution{

	public:
	int findSwapValues(int A[], int n, int B[], int m)
	{
        // Your code goes here
        unordered_map<int,int>mp;
        int sa=0,sb=0;
        for(int i=0;i<n;i++){
            sa+=A[i];
        }
        for(int i=0;i<m;i++){
            mp[B[i]]++;
            sb+=B[i];
        }
        for(int i=0;i<n;i++){
            int temp=sb-sa+2*A[i];
            if(temp%2!=0)
            continue;
            temp=temp/2;
            if(mp.find(temp)!=mp.end())
            return 1;
        }
        return -1;
	}
};