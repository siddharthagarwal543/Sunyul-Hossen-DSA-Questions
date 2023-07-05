//Problem link:https://leetcode.com/problems/sort-array-by-increasing-frequency/
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int hash[201]={0};
        for(auto it:nums){
            hash[it+100]++;
        }
        vector<int>ans;
        while(1){
            int mx=INT_MAX,idx=-1;
            for(int i=0;i<201;i++){
                if(mx>=hash[i]&&hash[i]!=0){
                    mx=hash[i];
                    idx=i;
                }
            }
            if(mx==INT_MAX)
            break;
            while(hash[idx]>0){
                ans.push_back(idx-100);
                hash[idx]--;
            }
        }
        return ans;
    }
};