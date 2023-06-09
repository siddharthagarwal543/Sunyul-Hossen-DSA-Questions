// https://practice.geeksforgeeks.org/problems/last-index-of-15847/1

class Solution{ //TC O(N) SC O(1)
    public:
    int lastIndex(string s) 
    {
        int idx=-1;//if not present, we have to return -1
        for(int i=0;i<s.length();i++){
            if(s[i]=='1')//update value of idx if 1 is value
            idx=i;
        }
        return idx;
    }

};

//Aprroach 2 same TC and SC but relatively faster
int lastIndex(string s) 
    {
        int idx=-1;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]=='1')
            return i;
        }
        return idx;
    }


//Similar question :https://www.interviewbit.com/problems/first-index/
vector<int> Solution::solve(vector<int> &A, vector<int> &B) { //TC O(n*m) SC O(1)
    vector<int>ans;
    for(int i=0;i<B.size();i++){
        int temp=-1;
        for(int j=0;j<A.size();j++){
            if(A[j]>=B[i]){
                temp=j;
                break;
            }
        }
       // temp=(temp==-1)?A.size():temp;
        ans.push_back(temp);
    }
    return ans;
}

vector<int> Solution::solve(vector<int> &A, vector<int> &B) {//TC O(Mlog(N)) SC O(1)
    for(int i=1;i<A.size();i++){
        A[i]=max(A[i-1],A[i]);
    }
    vector<int>ans;
    for(int i=0;i<B.size();i++){
        int l=0,r=A.size()-1;
        int temp=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(A[mid]>=B[i])
            {
                temp=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        ans.push_back(temp);
    }
    return ans;
}
