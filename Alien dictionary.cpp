//Problem link:https://practice.geeksforgeeks.org/problems/alien-dictionary/1
class Solution{
    private:
    vector<int>topological_sort(int v,vector<int>adj[]){
        int indegree[v]={0};
        for(int i=0;i<v;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<v;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int>topo;
        while(!q.empty()){
            int top=q.front();
            q.pop();
            topo.push_back(top);
            for(auto it:adj[top]){
                indegree[it]--;
                if(indegree[it]==0)
                q.push(it);
            }
        }
        return topo;
    }
    public:
    string findOrder(string dict[], int N, int K) {
        //code here
        vector<int>adj[K];
        for(int i=0;i<N-1;i++){
            string str1=dict[i],str2=dict[i+1];
            for(int j=0;j<min(str1.length(),str2.length());j++){
                if(str1[j]!=str2[j]){
                    adj[str1[j]-'a'].push_back(str2[j]-'a');
                    break;
                }
            }
        }
        vector<int>topo=topological_sort(K,adj);
        string ans="";
        for(auto it:topo){
            ans+=it+'a';
        }
        //cout<<ans<<" ";
        return ans;
    }
};