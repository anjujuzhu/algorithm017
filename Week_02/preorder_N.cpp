/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void preorders(Node* root, vector<int>& res) {
        if (!root) return;
        res.push_back(root->val);
        for (int i = 0; i < root->children.size(); ++i) {
            preorders(root->children[i], res);
        }
    }
    vector<int> preorder(Node* root) {
        vector<int> res;
        preorders(root, res);
        return res;
    }
};

//迭代
class Solution {
public:
    vector<int> preorder(Node* root) {
        stack<Node*> s;
        vector<int> res;
        if (!root) return res;
        s.push(root);
        while (!s.empty()) {
            Node *p = s.top();
            s.pop();
            res.push_back(p->val);
            for (int i = p->children.size() - 1; i >= 0; --i) {
                s.push(p->children[i]);
            }
        }
        return res;
    }
};