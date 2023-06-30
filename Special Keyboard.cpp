//Problem link:https://practice.geeksforgeeks.org/problems/special-keyboard3018/1
class Solution {
public:
    long long int optimalKeys(int N) {
        if (N <= 6)
            return N;

        vector<long long int> dp(N + 1);
        for (int i = 1; i <= 6; i++) {
            dp[i] = i;
        }

        for (int i = 7; i <= N; i++) {
            dp[i] = max(dp[i - 3] * 2, max(dp[i - 4] * 3, dp[i - 5] * 4));
        }

        return dp[N];
    }
};
