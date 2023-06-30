//Problem link:https://leetcode.com/problems/combination-sum-ii/description/
class Solution {
public:
    vector<vector<int>> ans;
    map<vector<int>, int> mp;

    void help(vector<int>& candidates, vector<int>& v, int idx, int sum, int target) {
        if (sum > target)
            return;

        if (sum == target) {
            ans.push_back(v);
            return;
        }

        for (int i = idx; i < candidates.size(); i++) {
            // Skip duplicates
            if (i > idx && candidates[i] == candidates[i - 1])
                continue;

            v.push_back(candidates[i]);
            help(candidates, v, i + 1, sum + candidates[i], target);
            v.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> v;
        help(candidates, v, 0, 0, target);
        return ans;
    }
};
