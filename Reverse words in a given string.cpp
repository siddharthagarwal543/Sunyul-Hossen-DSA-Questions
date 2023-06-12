//https://leetcode.com/problems/reverse-words-in-a-string/description/

class Solution {TC O(s.length()) SC O(s.length())
public:
    string reverseWords(string s) {
        int i=0;
        vector<vector<char>>v;
        string ans="";
        while(i<s.length()){//splitting string with delimiter " "
            int j=i;
            vector<char>temp;
            while(s[j]!=' '&&j<s.length()){
                temp.push_back(s[j]);
                j++;
            }
            if(temp.size()!=0)
            v.push_back(temp);
            i=j+1;
        }
        for(int i=v.size()-1;i>=0;i--){//adding substrings in the reverse order with ifs " "
            for(auto it:v[i]){
                ans+=it;
            }
            if(i!=0)
            ans+=" ";
        }
        return ans;
    }
};

/*
1. When a problem is asked to be solved in constant space, what should be the thought process?
A. While the idea may vary from problem to problem, swapping is a very common method used in problems requiring to be solved in constant space.

2. What is the time complexity of the swap function in C++?
A. The swap function in C++ works in O(1) time complexity.
*/