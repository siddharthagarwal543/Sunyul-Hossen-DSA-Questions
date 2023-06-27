//Problem link:https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
class Solution{//TC O(N) SC O(N) for rec call stack
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* node){
        // code here 
        if(node==NULL)
        return 0;
        return max(height(node->left),height(node->right))+1;
    }
};