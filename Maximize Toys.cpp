//Problem link:https://practice.geeksforgeeks.org/problems/maximize-toys0331/1
class Solution{
public:
    int toyCount(int N, int K, vector<int> arr)
    {
        // code here
        sort(arr.begin(),arr.end());
        int ans=0,i=0;
        while(i<arr.size()&&K>0){
            if(K-arr[i]>=0)
            {
                K-=arr[i];
                ans++;
            }
            i++;
            
        }
        return ans;
    }
};