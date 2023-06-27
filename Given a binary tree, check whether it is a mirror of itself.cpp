//Problem link:https://leetcode.com/problems/symmetric-tree/
class Solution {// TC O(min(N,M)) SC O(min(N,M)) for rec call stack
public:
    bool check(TreeNode* head1,TreeNode* head2)
    {
        if(head1==NULL&&head2==NULL)//both tree should have same length and same number of nodes
        return true;
        if((head1==NULL&&head2!=NULL)||(head1!=NULL&&head2==NULL))
        return false;
        if(head1->val!=head2->val)//if root node values are different, then they can never be symmetric
            return false;
        return (check(head1->left,head2->right))&&(check(head2->left,head1->right));//check for their alternate children
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
        return true;
        return check(root->left,root->right);
    }
};