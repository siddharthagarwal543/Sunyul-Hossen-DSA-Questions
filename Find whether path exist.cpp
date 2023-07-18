//Problem link: https://leetcode.com/problems/find-if-path-exists-in-graph/
class Solution {
public:
    void dfs(vector<vector<int>>&adj,vector<bool>&vis,int source){
        vis[source]=true;
        for(auto it:adj[source]){
            if(!vis[it])
            dfs(adj,vis,it);
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<bool>vis(n);
        queue<int>q;
        q.push(source);
        vis[source]=true;
        while(!q.empty()){
            int top=q.front();
            q.pop();
            for(auto it:adj[top]){
                if(!vis[it])
                {
                    q.push(it);
                    vis[it]=true;
                }
            }
        }
        
        return vis[destination];
    }
};