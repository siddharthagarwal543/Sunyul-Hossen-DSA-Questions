//Problem link:https://leetcode.com/problems/reorganize-string/description/
class Solution {
public:
    string reorganizeString(string s) {
        int n = s.length();
        int mx = (n % 2 == 0) ? (n / 2) : (n / 2 + 1);
        int cnt[26] = {0};
        
        for (auto it : s) {
            cnt[it - 'a']++;
        }
        
        for (int i = 0; i < 26; i++) {
            if (cnt[i] > mx)
                return "";
        }
        
        string ans = "";
        priority_queue<pair<int, char>> pq;
        
        for (int i = 0; i < 26; i++) {
            if (cnt[i] > 0)
                pq.push({cnt[i], 'a' + i});
        }
        
        while (!pq.empty()) {
            char curr = pq.top().second;
            int freq = pq.top().first;
            pq.pop();
            
            if (ans.empty() || ans.back() != curr) {
                ans += curr;
                if (freq > 1)
                    pq.push({freq - 1, curr});
            } else {
                if (pq.empty())
                    return "";
                
                char next = pq.top().second;
                int nextFreq = pq.top().first;
                pq.pop();
                
                ans += next;
                pq.push({freq, curr});
                if (nextFreq > 1)
                    pq.push({nextFreq - 1, next});
            }
        }
        
        return ans;
    }
};
