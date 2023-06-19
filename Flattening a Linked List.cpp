//Problem link: https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/
class Solution {// TC O(N) SC O(N) using queue
public:
    void traverse(Node* temp, queue<Node*>& q) {
        if (temp == NULL)
            return;
        
        q.push(temp);
        
        if (temp->child)
            traverse(temp->child, q);
        
        traverse(temp->next, q);
    }
    
    Node* flatten(Node* head) {
        if (!head)
            return NULL;
        
        queue<Node*> q;
        traverse(head, q);
        
        Node* temp = NULL;
        Node* prev = NULL;
        
        while (!q.empty()) {
            if (temp == NULL) {
                temp = q.front();
                head = temp;
            } else {
                temp->next = q.front();
                temp->next->prev = temp;
                temp = temp->next;
            }
            
            q.pop();
            prev = temp;
            temp->child = NULL;
        }
        
        return head;
    }
};

class Solution { // TC O(N)
public:
    Node* flatten(Node* head) {
        if (!head)
            return nullptr;

        Node* curr = head;
        while (curr) {
            if (curr->child) {
                Node* nextNode = curr->next;
                Node* childHead = flatten(curr->child);
                Node* childTail = childHead;

                while (childTail->next)
                    childTail = childTail->next;

                curr->next = childHead;
                childHead->prev = curr;

                if (nextNode) {
                    childTail->next = nextNode;
                    nextNode->prev = childTail;
                }

                curr->child = nullptr;
            }

            curr = curr->next;
        }

        return head;
    }
};
