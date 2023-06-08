//https://www.codingninjas.com/codestudio/problems/chocolate-problem_893280?leftPanelTab=1
#include <bits/stdc++.h> 
int findMinDiff(int n, int m, vector<int> chocolates) {
    // Write your code here.
    int i=0,j=m-1;
    int ans=INT_MAX;
    sort(chocolates.begin(),chocolates.end());
    while(j<chocolates.size()){
        ans=min(ans,chocolates[j++]-chocolates[i++]);
    }
    return ans;
}