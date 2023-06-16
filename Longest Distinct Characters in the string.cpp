//Problem Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
class Solution {//Windowing algorithm TC O(N) SC O(N)
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,h=0,ans=INT_MIN;
        unordered_map<char,int>mp;
        while(h<s.length()){
            if(mp.find(s[h])!=mp.end()&&l<h)
                while(mp.find(s[h])!=mp.end()&&l<h)
                {
                    mp[s[l]]--;
                    if(mp[s[l]]==0)
                    mp.erase(s[l]);
                    l++;
                }
             mp[s[h]]++;
            h++;
             ans=max(ans,h-l);
             cout<<h-l<<" "<<l<<" "<<h<<endl;
        }
        return ans==INT_MIN?0:ans;
    }
};

/*
How to count occurrences of each character of a string?
The occurrence of each character can be found by considering a frequency array.

What is the approach used to find the length of the longest non-repeating substring?
Sliding Window is the most efficient approach to solve this problem.
*/