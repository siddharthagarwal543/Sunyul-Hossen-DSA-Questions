//Problem link:https://leetcode.com/problems/gas-station/submissions/
class Solution {//TC O(N) SC o(1) if curr petrol level is less than 0 then take current station as starting else continue the previous trip
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start=0,i=0,curr=0,n=gas.size(),total=0;
        while(i<n){
            total+=gas[i]-cost[i];
            curr+=gas[i]-cost[i];
            if(curr<0){
                start=i+1;
                curr=0;
            }
            i++;
        }
        return total>=0?start:-1;
    }
};