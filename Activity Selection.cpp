//Problem link:https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int ans=1;
        int end=points[0][1];
        for(int i=1;i<points.size();i++){
            if(points[i][0]>end)
            {
                ans++;
               end=points[i][1];
               cout<<i<<" ";
            }
            else{
                 end=min(points[i][1],end);
            }
        }
        return ans;
    }
};