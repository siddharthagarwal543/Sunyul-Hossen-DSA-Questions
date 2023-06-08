//https://practice.geeksforgeeks.org/problems/convert-array-into-zig-zag-fashion1638/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
// User function template for C++
class Solution {//TC O(nlogn) SC O(1)
  public:
    // Program for zig-zag conversion of array
    void zigZag(int arr[], int n) {
        // code here
        sort(arr,arr+n);
        for(int i=1;i<n-1;i+=2){
            swap(arr[i],arr[i+1]);
        }
    }
};