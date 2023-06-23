//Problem link:https://www.interviewbit.com/problems/first-non-repeating-character-in-a-stream-of-characters/
string Solution::solve(string A) {
    vector<int>hash(26,0);
    queue<char>q;
    string ans="";
    for(auto it:A){
        if(hash[it-'a']==0)
        q.push(it);
        hash[it-'a']++;
        while(!q.empty()&&hash[q.front()-'a']>1)
        {
            q.pop();
        }
        if(!q.empty())
        {
            ans+=q.front();
        }
        else{
            ans+='#';
        }
    }
    return ans;
    
}
