//Problem link:https://practice.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
class Solution// TC O(min(N,M)) SC O(min(N,M)) for recursion call stack
{
    public:
    //Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2)
    {
        //Your Code here
        if((r1==NULL&&r2!=NULL)||(r1!=NULL&&r2==NULL))//if anyone is NULL then length of given trees are not same
        return false;
        if(r1==NULL&&r2==NULL)
        return true;
        bool isLeft=isIdentical(r1->left,r2->left),isRight=isIdentical(r1->right, r2->right);//checking children
        if(isLeft&&isRight&&r1->data==r2->data)//children and node data should be equal
        return true;
        return false;
    }
};