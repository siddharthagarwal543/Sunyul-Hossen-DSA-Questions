//Problem link:https://practice.geeksforgeeks.org/problems/count-distinct-elements-in-every-window/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
class Solution{
public:
    vector<int> countDistinct(int A[], int n, int k)
    {
        vector<int> ans;
        if (k > n)
            return ans;
        unordered_map<int, int> freq;
        int distinctCount = 0;
        int l = 0, r = 0;

        // Count distinct elements in the initial window
        while (r < k) {
            if (freq[A[r]] == 0)
                distinctCount++;
            freq[A[r]]++;
            r++;
        }
        ans.push_back(distinctCount);

        // Count distinct elements in the remaining windows
        while (r < n) {
            freq[A[l]]--;
            if (freq[A[l]] == 0)
                distinctCount--;
            l++;

            if (freq[A[r]] == 0)
                distinctCount++;
            freq[A[r]]++;
            r++;

            ans.push_back(distinctCount);
        }

        return ans;
    }
};
