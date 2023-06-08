//https://www.codingninjas.com/codestudio/problems/chocolate-problem_893280?leftPanelTab=1
#include <bits/stdc++.h> 
int findMinDiff(int n, int m, vector<int> chocolates) {
    // Two Pointer approach TC:O(nlogn) and SC:O(1)
    int i=0,j=m-1;
    int ans=INT_MAX;
    sort(chocolates.begin(),chocolates.end());
    while(j<chocolates.size()){
        ans=min(ans,chocolates[j++]-chocolates[i++]);
    }
    return ans;
}

/*
How do you solve the Chocolate Distribution Problem?
To solve the Chocolate Distribution Problem, you can sort the packets of chocolates in non-decreasing order of the number of chocolates in each packet and then distribute the packets starting from the smallest one. This ensures that each child gets at least one packet, and the difference between the maximum and minimum number of chocolates in the packets given to the children is minimised.

Can the Chocolate Distribution Problem have multiple solutions?
No, the Chocolate Distribution Problem has a unique solution, as the requirement is to minimise the difference between the maximum and minimum number of chocolates in the packets given to the children.

What if the number of children is greater than the number of packets of chocolates in the Chocolate Distribution Problem?
If the number of children is greater than the number of packets of chocolates, then it is impossible to give each child at least one packet. In such cases, the problem could be more solvable.

What is the significance of sorting the packets of chocolates in the Chocolate Distribution Problem?
Sorting the packets of chocolates in non-decreasing order of the number of chocolates in each packet ensures that the smallest packets are distributed first, which helps in minimising the difference between the maximum and minimum number of chocolates in the packets given to the children.

What if two packets of chocolates have the same number of chocolates in them in the Chocolate Distribution Problem?
If two packets of chocolates have the same number of chocolates in them, then it does not matter which packet is distributed first. The only requirement is that each child gets at least one packet of chocolates.
*/