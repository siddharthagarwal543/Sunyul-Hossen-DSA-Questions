//Problem link:https://leetcode.com/problems/binary-tree-maximum-path-sum/description/
class Solution {//using dfs kindof solution
public:
   int max_sum;

    int dfs(TreeNode* node){
        vector<int> own;

        if( node->left == nullptr && node->right==nullptr){
            max_sum = max(max_sum,node->val); 
            return node->val;
        }
        if(node->left != nullptr && node->right==nullptr){
            own.push_back(node->val);
            own.push_back( node->val + dfs(node->left) );
            int with_kid = *max_element(own.begin(),own.end());
            max_sum = max( max_sum, with_kid);
            return with_kid; 
        }else if(node->left==nullptr && node->right!=nullptr){
            own.push_back(node->val);
            own.push_back(node->val + dfs(node->right));
            int with_kid = *max_element(own.begin(),own.end());
            max_sum = max(max_sum,with_kid);  
            return with_kid; 
        }else{
            own.push_back(node->val);
            int go_right = dfs(node->right);
            int go_left = dfs(node->left);
            own.push_back( node->val + go_right ); 
            own.push_back( node->val + go_left );
            int with_kid = *max_element(own.begin(),own.end());

            max_sum = max(max_sum, node->val + go_left + go_right); 
            max_sum = max(max_sum, with_kid); 
            
            return with_kid; 
        }
    }
  int maxPathSum(TreeNode* root) {
        max_sum = INT_MIN;  
        int max_val_with_root = dfs(root);
        return max_sum ;
    }
};