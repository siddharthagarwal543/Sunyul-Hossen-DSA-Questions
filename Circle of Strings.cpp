//Problem link:https://practice.geeksforgeeks.org/problems/circle-of-strings4530/1
class Solution
{
    public:
    bool mark1[26]={false};
    void dfs(vector<int>&s,vector<int>adj[],bool mark[],int i)
    {
        mark[i]=true;
        for(auto x:adj[i])
        {
            if(!mark[x]) dfs(s,adj,mark,x);
        }
        s.push_back(i);
    }
    void dfs1(vector<int>adj1[],int i)
    {
        mark1[i]=true;
        for(auto x:adj1[i])
        {
            if(!mark1[x]) dfs1(adj1,x);
        }
       
    }
    int isCircle(int n, vector<string> a)
    {
        int indegree[26]={0};
        int outdegree[26]={0};
        vector<int>adj[26];
        for(int i=0;i<n;i++)
        {
            adj[a[i][0]-'a'].push_back(a[i][a[i].size()-1]-'a');
            indegree[a[i][a[i].size()-1]-'a']++;
            outdegree[a[i][0]-'a']++;
            
        }
        for(int i=0;i<26;i++)
        {
            if(indegree[i]!=outdegree[i]) return 0;
        }
        vector<int>s;
        bool mark[26]={false};
       for(int i=0;i<26;i++){
           
       if(outdegree[i]==0) continue;
        if(!mark[i]){
        dfs(s,adj,mark,i);
        }
       }
       vector<int>adj1[26];
       for(int i=0;i<n;i++)
        {
            adj1[a[i][a[i].size()-1]-'a'].push_back( a[i][0]-'a');
          
        }
     
       bool flag=true;
       
       for(int i=0;i<s.size();i++)
       {
          
           if(mark1[s[i]]==false)
           { 
                       if(flag==false) return 0;
                       flag=false;
                       dfs1(adj1,s[i]);

           }
           
       }
       return 1;
       
       
        
    }
};