//Problem link:https://practice.geeksforgeeks.org/problems/level-order-traversal-in-spiral-form/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
vector<int> findSpiral(Node* root) {// TC O(N) SC O(N) using two stacks, transfer nodes from one stack to another
    vector<int> result;
    if (root == NULL)
        return result;

    stack<Node*> s1;
    stack<Node*> s2;
    s1.push(root);

    while (!s1.empty() || !s2.empty()) {
        while (!s1.empty()) {
            Node* curr = s1.top();
            s1.pop();
            result.push_back(curr->data);

            if (curr->right)
                s2.push(curr->right);
            if (curr->left)
                s2.push(curr->left);
        }

        while (!s2.empty()) {
            Node* curr = s2.top();
            s2.pop();
            result.push_back(curr->data);

            if (curr->left)
                s1.push(curr->left);
            if (curr->right)
                s1.push(curr->right);
        }
    }

    return result;
}