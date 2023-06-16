//Problem link: https://leetcode.com/problems/longest-common-prefix/
class Solution {
public:
    class trieNode{
    public:
    char data;
    trieNode* children[58];
    bool isTerminal;
    int childCount;
    trieNode(char ch){
        data=ch;
        for(int i=0;i<58;i++)
        children[i]=NULL;
        childCount=0;
        isTerminal=false;
    }
};
    class Trie {
public:
    trieNode* root;
    Trie() {
        root=new trieNode('\0'); 
    }
    void insertUtil(trieNode* root,string word)
    {
        if(word.length()==0)
        {
            root->isTerminal=true;
            return;
        }
        int index=word[0]-'a';
        trieNode* child;
        if(root->children[index]!=NULL)
        child=root->children[index];
        else
        {
            child=new trieNode(word[0]);
            root->childCount++;
            root->children[index]=child;
        }
        insertUtil(child,word.substr(1));
    }
    void insert(string word) {
     insertUtil(root,word);   
    }

    void lcp(string word,string &ans)
    {
        for(int i=0;i<word.length();i++)
        {
            if(root->isTerminal)
            break;
            char ch=word[i];
            if(root->childCount==1)
            {
                ans.push_back(ch);
            int idx=ch-'a';
            root=root->children[idx];
            }
            else
            break;
        }


    }
};
    string longestCommonPrefix(vector<string>& strs) {
        
       Trie *t=new Trie();
       for(auto it:strs)
       t->insert(it);
       string ans="";
       t->lcp(strs[0],ans);
       return ans;
    }
};

/*
What is the best time and space complexity of finding the longest prefix string?
The best time complexity is O(N) and the space complexity is O(1) using the horizontal and vertical scanning approach.

Is the binary search approach better than the other approaches?
No, the binary search takes O(K*logN) time complexity. Hence, it is not the most efficient approach.
*/