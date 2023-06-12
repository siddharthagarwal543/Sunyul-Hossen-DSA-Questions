//https://leetcode.com/problems/longest-palindromic-substring/description/
class Solution {//using DP
public:
    int t[1001][1001];
    bool rec(string &s,int l,int r){
        if(l>=r)
        return true;
        if(t[l][r]!=-1)
        return t[l][r];
        if(s[l]==s[r]&&rec(s,l+1,r-1))
        {
            return t[l][r]=1;
        }
        return t[l][r]=0;
    }
    string longestPalindrome(string s) {
           if(s.length()==1)
        return s;
           for(int i=0;i<=s.length();i++)
        {
            for(int j=0;j<=s.length();j++)
            {
                t[i][j]=-1;
            }
        }
        int mx=0,l=0,r=0;
       for(int i=0;i<s.length();i++)
       {
           for(int j=i+1;j<s.length();j++)
           {
               if(rec(s,i,j)&&(j-i+1)>mx)
               {
                   l=i;
                   r=j;
                    mx=j-i+1;
               }
           }
       }
       
        string ans="";
        for(int i=l;i<=r;i++)
        {
            ans+=s[i];
        }
        return ans;
    }
};

/*
What is the longest palindrome sentence?
The largest known palindromic word is saippuakivikauppias (19 letters), which is Finnish for a dealer in lye (caustic soda).

What is the difference between substring and subsequence?
Substring: It is a prefix or suffix of a string.
Subsequence: It is a subset of the string’s character having the same sequential ordering as the original string.
*/