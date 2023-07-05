//Problem link:https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/
class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        for (int it : arr) {
            mp[(it % k + k) % k]++;
        }
        
        for (int i = 0; i < arr.size(); i++) {
            int remainder = (arr[i] % k + k) % k;
            if (mp.find((k - remainder) % k) != mp.end()) {
                mp[remainder]--;
                if (mp[remainder] == 0)
                    mp.erase(remainder);
                mp[(k - remainder) % k]--;
                if (mp[(k - remainder) % k] == 0)
                    mp.erase((k - remainder) % k);
            }
        }
        
        return mp.empty();
    }
};
