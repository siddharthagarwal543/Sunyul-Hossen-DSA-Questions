//Problem link:https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

class Solution// TC O(N) SC (N) using stack
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        vector<long long> v(n,-1);
        stack<long long>st;
        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push(i);
            }
            else if(arr[st.top()]<arr[i]){
                while(!st.empty()&&arr[st.top()]<arr[i])
                {v[st.top()]=arr[i];
                st.pop();}
                st.push(i);
            }
            else{
                st.push(i);
            }
        }
        return v;
    }
};

class Solution// TC O(N) SC O(1)
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        vector<long long> v(n,-1);
        long long mx=arr[n-1];
        for(int i=n-2;i>=0;i--){
          if(arr[i+1]>arr[i])
          v[i]=arr[i+1];
          else{
              if(v[i+1]>arr[i])
              v[i]=v[i+1];
              else if(mx>arr[i])
               {
                   int k = i + 1;
                    while (arr[k] <= arr[i]) {
                        k++;
                    }
                    v[i] = arr[k];
               }
          }
          mx=max(arr[i],mx);
        }
        return v;
    }
};