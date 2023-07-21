//Problem link:https://leetcode.com/problems/maximum-number-of-coins-you-can-get/description/
class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        int curr=0,mx=piles.size()/3;
        int total=0;
        while(curr<mx){
            total+=piles[piles.size()-2*curr-2];
            cout<<total<<" ";
            curr++;
        }
        return total;
    }
};