//Problem link:https://leetcode.com/problems/rotting-oranges/
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> v(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        int freshOranges = 0; // Counter for fresh oranges

        // Initialize the queue and count the number of fresh oranges
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    freshOranges++;
                }
            }
        }

        q.push({-1, -1});
        int minutes = 0;
        int rottenOranges = 0; // Counter for rotten oranges

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            if (row == -1) {
                // Indicates the end of a minute
                if (!q.empty()) {
                    q.push({-1, -1});
                }
                minutes++;
            } else {
                // Check adjacent cells and propagate rot
                if (row > 0 && grid[row - 1][col] == 1) {
                    grid[row - 1][col] = 2;
                    q.push({row - 1, col});
                    rottenOranges++;
                }
                if (row < m - 1 && grid[row + 1][col] == 1) {
                    grid[row + 1][col] = 2;
                    q.push({row + 1, col});
                    rottenOranges++;
                }
                if (col > 0 && grid[row][col - 1] == 1) {
                    grid[row][col - 1] = 2;
                    q.push({row, col - 1});
                    rottenOranges++;
                }
                if (col < n - 1 && grid[row][col + 1] == 1) {
                    grid[row][col + 1] = 2;
                    q.push({row, col + 1});
                    rottenOranges++;
                }
            }
        }

        if (rottenOranges == freshOranges) {
            return minutes - 1; // Subtract 1 because the last minute is not counted
        } else {
            return -1;
        }
    }
};
