//Problem link:https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
class Solution {// TC O(N) SC O(N) using level order traversal and keep last nodes of each line
  public:
    vector <int> bottomView(Node *root) {
        vector<int>ans;
        queue<pair<Node*,int>>q;
        map<int,Node*>mp;
        q.push({root,0});
        while(!q.empty()){
            Node* curr=q.front().first;
            int count=q.front().second;
            mp[count]=curr;
            q.pop();
            if(curr->left)
            q.push({curr->left,count-1});
            if(curr->right)
            q.push({curr->right,count+1});
        }
        for(auto it:mp){
            ans.push_back(it.second->data);
        }
        return ans;
    }
};
//Similar questions : https://www.interviewbit.com/problems/vertical-order-traversal-of-binary-tree/ ,https://www.interviewbit.com/problems/right-view-of-binary-tree/
/*
What is the left view of a binary tree?
The set of nodes visible when the tree is visited from the left is the left view of the binary tree.

How do you print the bottom of a binary tree?
The bottom view of a binary tree can be printed by hashing and level order traversal of the binary tree.

What is the diameter of a binary tree?
The diameter of a tree is the number of nodes on the longest path between two leaves in the tree
*/