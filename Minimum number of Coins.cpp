//Problem link:https://leetcode.com/problems/coin-change/
class Solution {
public:
    int t[13][10001];
    
    int help(int idx, vector<int>& coins, int amount) {
        if (amount == 0)
            return 0;
        if (idx == coins.size())
            return INT_MAX - 1;
        if (t[idx][amount] != -1)
            return t[idx][amount];

        int include = INT_MAX, exclude = INT_MAX;
        if (coins[idx] <= amount)
            include = 1 + help(idx, coins, amount - coins[idx]);
        exclude = help(idx + 1, coins, amount);

        return t[idx][amount] = min(include, exclude);
    }

    int coinChange(vector<int>& coins, int amount) {
        memset(t, -1, sizeof(t));
        int ans = help(0, coins, amount);
        return (ans == INT_MAX - 1) ? -1 : ans;
    }
};
