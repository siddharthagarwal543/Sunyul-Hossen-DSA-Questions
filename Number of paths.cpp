//Problem link:https://leetcode.com/problems/unique-paths/description/
#include <vector>

using namespace std;

class Solution {
public:
    int t[101][101];
    
    int uniquePathsHelper(int row, int col, int m, int n) {
        if (row == m && col == n) {//we have reached end point
            return 1;
        }
        
        if (row > m || col > n) {//we had thought out of the bord :)
            return 0;
        }
        
        if (t[row][col] != -1) {//ans is pre calculated
            return t[row][col];
        }
        
        if (row == m) {//robot can move only in straight line
            return t[row][col] = uniquePathsHelper(row, col + 1, m, n);
        }
        
        if (col == n) {
            return t[row][col] = uniquePathsHelper(row + 1, col, m, n);
        }
        
        return t[row][col] = uniquePathsHelper(row, col + 1, m, n) + uniquePathsHelper(row + 1, col, m, n);//checking for both possible move
    }
    
    int uniquePaths(int m, int n) {
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                t[i][j] = -1;
            }
        }
        
        return uniquePathsHelper(1, 1, m, n);
    }
};
class Solution {//iterative
public:
    int uniquePaths(int m, int n) {
        int arr[m][n];
        for(int i=0;i<m;i++)
            arr[i][0]=1;
        for(int i=0;i<n;i++)
            arr[0][i]=1;
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                arr[i][j]=arr[i-1][j]+arr[i][j-1];
            }
        }
        return arr[m-1][n-1];
    }
};
class Solution {//O(N) solution
public:
    int uniquePaths(int m, int n) {
       long ans = 1;
        for(int i = m+n-2, j = 1; i >= max(m, n); i--, j++) 
            ans = (ans * i) / j;
        return ans;
    }
};