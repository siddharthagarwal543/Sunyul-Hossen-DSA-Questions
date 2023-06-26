//Problem link:https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
class Solution {// TC O(N) SC O(1)
public:
    bool hasNode(TreeNode*parent, TreeNode*child){
        if(parent==child)
        return true;
        if(parent==NULL)
        return false;
        if(parent->left&&parent->val>child->val)
        return hasNode(parent->left,child);
        else if(parent->right&&parent->val<child->val)
        return hasNode(parent->right,child);
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==p||root==q)
        return root;
        if(hasNode(root->left,p)&&hasNode(root->left,q))
        return lowestCommonAncestor(root->left,p,q);
        if(hasNode(root->right,p)&&hasNode(root->right,q))
        return lowestCommonAncestor(root->right,p,q);
         if((hasNode(root->left,p)&&hasNode(root->right,q))||(hasNode(root->left,q)&&hasNode(root->right,p)))
        return root;
        return NULL;
    }
};