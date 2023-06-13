//https://practice.geeksforgeeks.org/problems/check-if-string-is-rotated-by-two-places-1587115620/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
 bool isRotated(string str1, string str2) //TC O(N) SCo(1) checking both possible strings after rotations
    {
        // Your code here
        if(str1.length()<2){//if length is less than 2 we can't rotate it, edge case
            return str1==str2;
        }
        int n=str1.length();
        return (str2.substr(n-2,2)+str2.substr(0,n-2)==str1||str2.substr(2,n-2)+str2.substr(0,2)==str1)?true:false;
    }

//Similar question : https://www.interviewbit.com/problems/stringoholics/