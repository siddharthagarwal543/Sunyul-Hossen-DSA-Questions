//https://www.interviewbit.com/problems/anagrams/
vector<vector<int> > Solution::anagrams(const vector<string> &A) {//TC O(n*mlogm) mlogm for sorting and n for traversing, SCO(N*M)
    unordered_map<string,vector<int>>mp;//we will sort and add string in it
    int n=A.size();
    vector<vector<int>>ans;
    for(int i=0;i<n;i++){
        string temp=A[i];//We can't modify orignal string
        sort(temp.begin(),temp.end());
        mp[temp].push_back(i+1);
    }
    for(auto i:mp){
        ans.push_back(i.second);
    }
    return ans;
}

//Similar question: https://leetcode.com/problems/group-anagrams/