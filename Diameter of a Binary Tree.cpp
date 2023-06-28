//Problem link:https://leetcode.com/problems/diameter-of-binary-tree/description/
class Solution {
public:
    int height(TreeNode* root){
        if(root==NULL)
        return 0;
        return max(height(root->left),height(root->right))+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {//TC O(N) SC O(N)
        if(root==NULL)
        return 0;
        return max(height(root->left)+height(root->right),max(diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right)));
    }//3 cases possible i)Diameter inc root node ii) max diameter lies in left half iii) max diameter lies in right half
};