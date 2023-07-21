//Problem link:https://leetcode.com/problems/snakes-and-ladders/description/
class Solution {
public:
    int bfs(unordered_map<int,int>&mp,int start,int n){
        queue<int>q;
        q.push(start);
        set<int>vis;
        vis.insert(start);
        int steps=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int curr=q.front();
                q.pop();
                if(curr==n*n)
                return steps;
                for(int next=curr+1;next<=curr+6;next++){
                    int actual=(mp.find(next)!=mp.end())?mp[next]:next;
                    if(vis.find(actual)!=vis.end())
                    continue;
                    vis.insert(actual);
                    q.push(actual);
                }
            }
            steps++;
        }
        return -1;
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        //how to deal with numbering style?
        // make a queue and add all the possiblites
        //maintain a visited array too
        int n=board.size();
        unordered_map<int,int>mp;
        for(int i=n-1;i>=0;i--){
            int actualRow=(n-i-1);
            int low=(actualRow*n)+1,high=low+n-1;
            int fwd=low,rev=high;
            for(int j=0;j<n;j++){
                int actualCell=(actualRow%2==0)?fwd:rev;
                if(board[i][j]!=-1)
                mp[actualCell]=board[i][j];
                fwd++;
                rev--;
            }
        }
         int ans=bfs(mp,1,n);
            return ans==INT_MAX?-1:ans;
    }
};