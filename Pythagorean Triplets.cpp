//https://www.interviewbit.com/problems/pythagorean-triplets/#:~:text=A%20Pythagorean%20triplet%20is%20a,%2B%20b2%20%3D%20c2.

bool help(int n){//check whether c is a perfect square
    if(n>0)
    {
        int sr=sqrt(n);
        return sr*sr==n;
    }
    return false;
}

int Solution::solve(int A) {
     int ans=0;
    for(int i=1;i<=A;i++){
        for(int j=1;j*j<i*i;j++){
            int c=i*i-j*j;//checking if there exist a c such that i*i=j*j+c;
            if(help(c)&&j*j+c==i*i&&j*j<c)
           {
                ans++;
           }
        }
    }
    return ans;
}
