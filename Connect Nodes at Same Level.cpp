//Problem link:https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
class Solution {// TC O(N) SC O(N)
public:
    Node* connect(Node* root) {
        if(root==NULL)
        return NULL;
        queue<Node*>q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            Node* curr=q.front();
            q.pop();
            if(curr==NULL)
            {
                if(!q.empty())
                q.push(NULL);
            }
            else{
                if(curr->left)
                q.push(curr->left);
                if(curr->right)
                q.push(curr->right);
                if(q.front())
                curr->next=q.front();
                else
                curr->next=NULL;
            }

        }
        return root;
    }
};