//https://leetcode.com/problems/coin-change/description/
class Solution {
public:
    int t[13][10001];
    int help(int idx, vector<int>& nums, int sum) {
        if (sum == 0) {
            return 0;
        }
        if (idx == nums.size() || sum < 0) {
            return INT_MAX-1; // Invalid combination
        }
        if(t[idx][sum]!=-1)
        return t[idx][sum];
        int ans = help(idx + 1, nums, sum);
        if(sum>=nums[idx])
        ans=min(ans,help(idx,nums,sum-nums[idx])+1);
        return t[idx][sum]=ans;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        for(int i=0;i<=coins.size();i++){
            for(int j=0;j<=amount;j++){
                t[i][j]=-1;
            }
        }
        int result = help(0, coins, amount);
        return result>=INT_MAX-1?-1:result;
    }
};
