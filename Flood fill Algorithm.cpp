//Problem link:https://leetcode.com/problems/flood-fill/description/
#include <vector>

using namespace std;

class Solution {
public:
    void floodFillDFS(vector<vector<int>>& image, int row, int col, int newColor, vector<vector<bool>>& visited, int reqColor) {
        // Check boundary conditions and color match
        if (row < 0 || col < 0 || row >= image.size() || col >= image[0].size() || visited[row][col] || image[row][col] != reqColor) {
            return;
        }
        
        visited[row][col] = true;
        image[row][col] = newColor;
        
        // Recursively perform flood fill in all four directions
        floodFillDFS(image, row + 1, col, newColor, visited, reqColor); // Down
        floodFillDFS(image, row - 1, col, newColor, visited, reqColor); // Up
        floodFillDFS(image, row, col + 1, newColor, visited, reqColor); // Right
        floodFillDFS(image, row, col - 1, newColor, visited, reqColor); // Left
    } 
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image.empty() || image[0].empty()) {
            return image;
        }
        
        int rows = image.size();
        int cols = image[0].size();
        
        vector<vector<bool>> visited(rows, vector<bool>(cols, false)); // Initialize visited matrix
        
        int reqColor = image[sr][sc]; // Color of the starting pixel
        
        floodFillDFS(image, sr, sc, newColor, visited, reqColor);
        
        return image;
    }
};

#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int rows = image.size();
        int cols = image[0].size();
        int reqColor = image[sr][sc];

        if (reqColor == newColor) {
            // No need to perform flood fill if the new color is the same as the original color
            return image;
        }

        stack<pair<int, int>> st;
        st.push({sr, sc});

        while (!st.empty()) {
            pair<int, int> curr = st.top();
            st.pop();
            int row = curr.first;
            int col = curr.second;

            if (image[row][col] != reqColor) {
                continue;
            }

            image[row][col] = newColor;

            // Explore neighboring pixels in all four directions
            if (row - 1 >= 0) {
                st.push({row - 1, col}); // Up
            }
            if (row + 1 < rows) {
                st.push({row + 1, col}); // Down
            }
            if (col - 1 >= 0) {
                st.push({row, col - 1}); // Left
            }
            if (col + 1 < cols) {
                st.push({row, col + 1}); // Right
            }
        }

        return image;
    }
};

