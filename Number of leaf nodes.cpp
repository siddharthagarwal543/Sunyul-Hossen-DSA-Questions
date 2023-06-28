//Problem link:https://practice.geeksforgeeks.org/problems/count-leaves-in-binary-tree/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
int countLeaves(Node* root)//TC O(N) SC O(N)
{
  // Your code here
  if(root==NULL)
  return 0;
  if(root->left==NULL&&root->right==NULL)
  return 1;
  int ans=0;
  if(root->left!=NULL)
  ans+=countLeaves(root->left);
  if(root->right!=NULL)
  ans+=countLeaves(root->right);
  return ans;
}

//Similar question:https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/