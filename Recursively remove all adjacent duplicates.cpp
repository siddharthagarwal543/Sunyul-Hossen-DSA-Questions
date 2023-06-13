//https://www.interviewbit.com/problems/remove-consecutive-characters/
string Solution::solve(string A, int B) {// TC O(N) SC O(1)
    int i=0;
   while(i<A.length()){
       int j=i;
       int cnt=0;
       for(j;j<A.length();j++){
           if(A[i]==A[j])
           cnt++;
           else
           break;
       }
       if(cnt==B)
       A.erase(i,cnt);
       else
       i=j;
   }
    return A;
}
