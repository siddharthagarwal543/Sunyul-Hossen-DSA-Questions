//Problem link:https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
vector<int> leftView(Node *root)
{
   // Your code here
   queue<Node*>q;
   q.push(root);
   vector<int>ans;
   if(root==NULL)
   return ans;
   q.push(NULL);
   ans.push_back(root->data);
   while(!q.empty()){
       if(q.front()==NULL){
           q.pop();
           if(q.size()!=0){
               ans.push_back(q.front()->data);
               q.push(NULL);
           }
           
       }
       else{
           Node*temp=q.front();
           q.pop();
           if(temp->left){
               q.push(temp->left);
           }
           if(temp->right){
               q.push(temp->right);
           }
       }
   }
   return ans;
}
