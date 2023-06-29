//Problem link:https://practice.geeksforgeeks.org/problems/heap-sort/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

class Solution
{
     
    public:
    //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)  
    {
      // Your Code Here
        int largest = i, left = 2*i+1, right = 2*i+2;
       if(left < n && arr[left] > arr[largest])
            largest = left;
       if(right < n && arr[right] > arr[largest])
        largest = right;
       if(largest != i){
           swap(arr[i], arr[largest]);
           heapify(arr, n, largest);
       }
    }

public:
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    { 
    // Your Code Here
     for(int i=(n-2)/2;i>=0;i--)
    heapify(arr,n,i);
    }
    
  

    
    public:
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        //code here
        buildHeap(arr,n);
        for(int i=n-1;i>=0;i--)
        {
            swap(arr[i],arr[0]);
            heapify(arr,i,0);
        }
    }
};

/*
Advantages of Heap Sort:
Efficiency –  The time required to perform Heap sort increases logarithmically while other algorithms may grow exponentially slower as the number of items to sort increases. This sorting algorithm is very efficient.
Memory Usage – Memory usage is minimal because apart from what is necessary to hold the initial list of items to be sorted, it needs no additional memory space to work
Simplicity –  It is simpler to understand than other equally efficient sorting algorithms because it does not use advanced computer science concepts such as recursion.
Disadvantages of Heap Sort:
Costly: Heap sort is costly.
Unstable: Heap sort is unstable. It might rearrange the relative order.
Efficient: Heap Sort is not very efficient when working with highly complex data. 
Frequently Asked Questions Related to Heap Sort
Q1. What are the two phases of Heap Sort?

The heap sort algorithm consists of two phases. In the first phase, the array is converted into a max heap. And in the second phase, the highest element is removed (i.e., the one at the tree root) and the remaining elements are used to create a new max heap.

Q2. Why Heap Sort is not stable?

The heap sort algorithm is not a stable algorithm. This algorithm is not stable because the operations that are performed in a heap can change the relative ordering of the equivalent keys.
Q3. Is Heap Sort an example of the “Divide and Conquer” algorithm?

Heap sort is NOT at all a Divide and Conquer algorithm. It uses a heap data structure to efficiently sort its element and not a “divide and conquer approach” to sort the elements.

Q4. Which sorting algorithm is better – Heap sort or Merge Sort?

The answer lies in the comparison of their time complexity and space requirements. The Merge sort is slightly faster than the Heap sort. But on the other hand merge sort takes extra memory. Depending on the requirement, one should choose which one to use.

Q5. Why is Heap sort better than Selection sort?

Heap sort is similar to selection sort, but with a better way to get the maximum element. It takes advantage of the heap data structure to get the maximum element in constant time 
*/

