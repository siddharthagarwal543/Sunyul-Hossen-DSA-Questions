//Problem link:https://leetcode.com/problems/lru-cache/
struct Node {
    int key;
    int val;
    Node *next;
    Node *prev;
    Node(int key, int val) : key(key), val(val), next(nullptr), prev(nullptr) {}
};
class LRUCache {
public:
unordered_map<int,Node*>mp;
Node* head=new Node(-1,-1),*tail=new Node(-1,-1);
int size;
    LRUCache(int capacity) {
        size=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
      if(mp.find(key)==mp.end())
      return -1;
      Node* node=mp[key];
      remove(node);
      add(node);
      return node->val;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end())
        remove(mp[key]);
        Node* node=new Node({key,value});
        mp[key]=node;
        add(node);
        if(mp.size()>size){
            Node* del=head->next;
            remove(del);
            mp.erase(del->key);
        }
    }

     void add(Node *node) {
        Node *previousEnd = tail->prev;
        previousEnd->next = node;
        node->prev = previousEnd;
        node->next = tail;
        tail->prev = node;
    }
    
    void remove(Node *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
};