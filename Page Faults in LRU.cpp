//Problem link:https://practice.geeksforgeeks.org/problems/page-faults-in-lru5603/1
class Solution{
public:
    int pageFaults(int N, int C, int pages[]){
        unordered_map<int, int> mp; // To store the frequency of pages
        deque<int> dq; // To store the pages in the order of their accesses (doubly linked list)

        int pageFaults = 0;
        for (int i = 0; i < N; i++) {
            if (mp.find(pages[i]) == mp.end()) {
                // Page fault occurs
                if (dq.size() == C) {
                    // Memory is full, remove the least recently used page (front of the queue)
                    int lruPage = dq.front();
                    dq.pop_front();
                    mp.erase(lruPage);
                }
                dq.push_back(pages[i]); // Add the new page to the end of the queue
                mp[pages[i]] = 1; // Update its frequency in the map
                pageFaults++; // Increment the page fault count
            } else {
                // Page hit, move the page to the end of the queue (most recently used)
                dq.erase(find(dq.begin(), dq.end(), pages[i]));
                dq.push_back(pages[i]);
            }
        }

        return pageFaults;
    }
};
