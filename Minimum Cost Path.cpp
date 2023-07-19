//Problem link: https://leetcode.com/problems/minimum-path-sum/
#include <vector>

class Solution {
public:
    int t[201][201]; 

    int solve(int i, int j, std::vector<std::vector<int>>& grid) {
        if (i == grid.size() - 1 && j == grid[0].size() - 1)
            return grid[i][j];
        
        if (t[i][j] != -1)
            return t[i][j];
        
        int down = (i + 1 < grid.size()) ? solve(i + 1, j, grid) : INT_MAX;
        int right = (j + 1 < grid[0].size()) ? solve(i, j + 1, grid) : INT_MAX;
        
        return t[i][j] = std::min(down, right) + grid[i][j];
    }

    int minPathSum(std::vector<std::vector<int>>& grid) {
        for (int i = 0; i <= 200; i++) {
            for (int j = 0; j <= 200; j++) {
                t[i][j] = -1;
            }
        }
        return solve(0, 0, grid);
    }
};
