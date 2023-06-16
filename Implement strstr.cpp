//Problem link: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/
class Solution {//Windowing algorithm, TC O(N) SC O(N)
public:
    int strStr(string haystack, string needle) {
     int i=0;
     if(haystack.size()<needle.size())
     return -1;
     if(haystack==needle)
     return 0;
     string temp="";
     for(int j=0;j<=haystack.size()-needle.size();j++)
     {   
         temp+=haystack[j];
         if(temp.size()==needle.size())
         {
             if(temp==needle)
             return j-needle.size();
             else
             temp=haystack[j];
         }
     } 
     return -1;
    }
};