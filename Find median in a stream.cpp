//Problem link:https://leetcode.com/problems/find-median-from-data-stream/description/
#include<queue>
class MedianFinder {//TC O(logN) SC O(N/2)
public:
     priority_queue<int> maxHeap; // Max-heap for smaller half
    priority_queue<int, vector<int>, greater<int>> minHeap; // Min-heap for larger half
    MedianFinder() {
    }
    
    void addNum(int num) {
         if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }
        
        // Balance the heaps if necessary
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
       if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        } else {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
    }
};