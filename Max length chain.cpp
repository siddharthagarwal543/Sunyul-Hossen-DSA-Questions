//Problem link:https://leetcode.com/problems/maximum-length-of-pair-chain/
class Solution {
public:
    int t[1001];

    int help(int idx, vector<vector<int>>& pairs) {
        if (pairs.size() == idx)
            return 0;
        if (t[idx] != -1)
            return t[idx];

        t[idx]=1;
        for(int j=idx+1;j<pairs.size();j++){
            if(pairs[idx][1]<pairs[j][0])
            t[idx]=max(t[idx],1+help(j,pairs));
        }
        return t[idx];
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end());

        for (int i = 0; i <= 1000; i++) {
            t[i] = -1;
        }

        int ans=0;
        for(int i=0;i<pairs.size();i++){
            ans=max(ans,help(i,pairs));
        }
        return ans;
    }
};