//https://practice.geeksforgeeks.org/problems/unsorted-array4925/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
int findElement(int arr[], int n) {//TC:O(n) and SC:O(n)
    //storing prefix max element
    int prefix[n];
    prefix[0]=-1;
    for(int i=1;i<n;i++){
        prefix[i]=max(prefix[i-1],arr[i-1]);
    }
    //storing min element
    int suffix[n];
    suffix[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--){
        suffix[i]=min(suffix[i+1],arr[i+1]);
    }
    //comparing condition for every ele of array
    for(int i=1;i<n-1;i++){
            if(arr[i]>=prefix[i]&&arr[i]<=suffix[i])
            return arr[i];
    }
    return -1;
}