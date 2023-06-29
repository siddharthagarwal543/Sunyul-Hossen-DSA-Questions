//Problem link:https://leetcode.com/problems/kth-largest-element-in-a-stream/description/
class KthLargest {
public:
    int lim; // Maximum capacity (k)
    priority_queue<int, vector<int>, greater<int>> pq; // Min heap to store the k largest elements

    KthLargest(int k, vector<int>& nums) {
        lim = k;

        // Initialize the min heap with the first k elements
        for (auto num : nums) {
            pq.push(num);
            if (pq.size() > lim) {
                pq.pop(); // Remove the smallest element if the heap exceeds k elements
            }
        }
    }
    
    int add(int val) {
        pq.push(val); // Add the new element to the heap
        if (pq.size() > lim) {
            pq.pop(); // Remove the smallest element if the heap exceeds k elements
        }
        return pq.top(); // Return the current kth largest element
    }
};
