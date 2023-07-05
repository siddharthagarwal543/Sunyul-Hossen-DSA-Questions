//Problem link:https://leetcode.com/problems/intersection-of-two-arrays/
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        unordered_map<int,int>mp;
        for(auto it:nums1){
            mp[it]++;
        }
        for(auto it:nums2){
            if(mp.find(it)!=mp.end()&&mp[it]!=-1){
                mp[it]=-1;
                ans.push_back(it);
            }
        }
        return ans;
    }
};
