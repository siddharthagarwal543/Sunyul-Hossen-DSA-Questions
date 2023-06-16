//Problem link: https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
class Solution {
public:
    int rec(string& s, int l, int h, vector<vector<int>>& t) {
        if (l >= h)
            return 0;
        if (t[l][h] != -1)
            return t[l][h];
        if (s[l] == s[h]) {
            return t[l][h] = rec(s, l + 1, h - 1, t);
        }
        else {
            return t[l][h] = min(rec(s, l + 1, h, t), rec(s, l, h - 1, t)) + 1;
        }
    }

    int minInsertions(string s) {
        int n = s.length();
        vector<vector<int>> t(n, vector<int>(n, -1));
        return rec(s, 0, n - 1, t);
    }
};

//Similar question:https://www.interviewbit.com/problems/minimum-characters-required-to-make-a-string-palindromic/