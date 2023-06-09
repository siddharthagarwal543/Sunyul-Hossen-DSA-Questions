//Problem link: https://leetcode.com/problems/spiral-matrix/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int sr=0,sc=0,er=matrix.size()-1,ec=matrix[0].size()-1;
        vector<int>ans;
        int cnt=0,total=matrix.size()*matrix[0].size();
        while(cnt<total){
            for(int i=sc;i<=ec&&cnt<total;i++)
            {
                ans.push_back(matrix[sr][i]);
                cnt++;
            }
            sr++;
            for(int i=sr;i<=er&&cnt<total;i++){
                ans.push_back(matrix[i][ec]);
                cnt++;
            }
            ec--;
            for(int i=ec;i>=sc&&cnt<total;i--){
                ans.push_back(matrix[er][i]);
                cnt++;
            }
            er--;
            for(int i=er;i>=sr&&cnt<total;i--){
                ans.push_back(matrix[i][sc]);
                cnt++;
            }
            sc++;
        }
        return ans;
    }
};