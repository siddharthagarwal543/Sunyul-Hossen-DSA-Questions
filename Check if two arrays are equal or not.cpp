//Problem link:https://practice.geeksforgeeks.org/problems/check-if-two-arrays-are-equal-or-not3847/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
class Solution{
    public:

    //Function to check if two arrays are equal or not.
    bool check(vector<ll> A, vector<ll> B, int N) {
        //code hereit
        unordered_map<int,int>mp;
        for(auto it:A){
            mp[it]++;
        }
        for(auto it:B){
            mp[it]--;
        }
        for(auto it:mp){
            if(it.second!=0)
            return false;
        }
        return true;
    }
};

class Solution{
    public:

    //Function to check if two arrays are equal or not.
    bool check(vector<ll> A, vector<ll> B, int N) {
        //code hereit
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        return A==B;
    }
};