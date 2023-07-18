//Question link: https://practice.geeksforgeeks.org/problems/minimum-indexed-character-1587115620/1
class Solution
{
  public:
    //Function to find the minimum indexed character.
    int minIndexChar(string str, string patt)
    {
        // Your code here
        unordered_map<char,int>mp;
        for(auto it:patt)
        mp[it]++;
        for(int i=0;i<str.length();i++)
        {
            if(mp.find(str[i])!=mp.end())
            return i;
        }
        return -1;
        
    }
};

class Solution
{
  public:
    //Function to find the minimum indexed character.
    int minIndexChar(string str, string patt)
    {
        // Your code here
        int arr[26]={0};
        for(auto it:patt)
        arr[it-'a']++;
        for(int i=0;i<str.length();i++)
        {
            if(arr[str[i]-'a']>0)
            return i;
        }
        return -1;
        
    }
};