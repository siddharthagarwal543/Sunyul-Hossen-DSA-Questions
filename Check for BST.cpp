//Problem link:https://leetcode.com/problems/validate-binary-search-tree/
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBSTHelper(root, LONG_MIN, LONG_MAX);
    }
    
    bool isValidBSTHelper(TreeNode* root, long long minVal, long long maxVal) {
        if (root == nullptr) {
            return true;
        }
        
        if (root->val <= minVal || root->val >= maxVal) {
            return false;
        }
        
        bool isLeftValid = isValidBSTHelper(root->left, minVal, root->val);
        bool isRightValid = isValidBSTHelper(root->right, root->val, maxVal);
        
        return isLeftValid && isRightValid;
    }
};