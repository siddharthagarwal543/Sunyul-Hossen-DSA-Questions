//Problem link:https://leetcode.com/problems/merge-k-sorted-lists/description/
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Custom comparison function for the priority queue
        auto compare = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };

        // Create a min heap using a priority queue
        priority_queue<ListNode*, vector<ListNode*>, decltype(compare)> pq(compare);

        // Push the head nodes of all linked lists into the priority queue
        for (auto list : lists) {
            if (list) {
                pq.push(list);
            }
        }

        // Create a dummy node as the head of the merged list
        ListNode dummy(0);
        ListNode* tail = &dummy;

        // Merge the lists until the priority queue is empty
        while (!pq.empty()) {
            // Get the node with the smallest value from the priority queue
            ListNode* node = pq.top();
            pq.pop();

            // Append the node to the merged list
            tail->next = node;
            tail = tail->next;

            // Move to the next node in the list
            if (node->next) {
                pq.push(node->next);
            }
        }

        return dummy.next;
    }
};
