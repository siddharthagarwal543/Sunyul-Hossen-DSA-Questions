//https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
#include <vector>
using namespace std;

class Solution {
public:
    int t[1001];
    
    int maxSumIS(int arr[], int n) {
        vector<int> dp(n, 0);
        for (int i = 0; i < n; i++) {
            dp[i] = arr[i];
            for (int j = 0; j < i; j++) {
                if (arr[i] > arr[j]) {
                    dp[i] = max(dp[i], dp[j] + arr[i]);
                }
            }
        }
        
        int maxSum = 0;
        for (int i = 0; i < n; i++) {
            maxSum = max(maxSum, dp[i]);
        }
        return maxSum;
    }
};