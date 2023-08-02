//https://leetcode.com/problems/edit-distance/description/
class Solution {
public:
    int t[501][501];
    
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (i == 0 || j == 0)
                    t[i][j] = i + j;
                else if (word1[i - 1] == word2[j - 1])
                    t[i][j] = t[i - 1][j - 1];
                else
                    t[i][j] = 1 + min(t[i - 1][j], min(t[i][j - 1], t[i - 1][j - 1]));
            }
        }
        
        return t[n][m];
    }
};
