//Problem link:https://practice.geeksforgeeks.org/problems/josephus-problem/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
class Solution
{
    public:
     int josephusReal(int n, int k)
    {
        if(n==1)
            return 0;
        else
            return ((josephusReal(n-1,k)+k)%(n));
    }
    int josephus(int n, int k)
    {
       //Your code here
      return josephusReal(n,k)+1;
      
    }
};