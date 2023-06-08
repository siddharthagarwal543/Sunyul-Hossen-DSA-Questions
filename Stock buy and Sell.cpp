//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int>mx(n,0);//for storing the price on which we will sell stock if we will purchase it on the ith day
        for(int i=n-2;i>=0;i--){
            mx[i]=max(mx[i+1],prices[i+1]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,mx[i]-prices[i]);//checking whether we will generate max profit if we will buy stock on the ith day
        }
        return ans;
    }
};