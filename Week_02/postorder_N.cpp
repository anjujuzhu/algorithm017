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
//递归
class Solution {
public:
    void postorders(Node* root, vector<int>& res) {
        if (!root) return;
        if (root->children.size() != 0){
            for (int i = 0; i < root->children.size(); ++i) {
                postorders(root->children[i], res);
            }
        } 
        res.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
        vector<int> res;
        postorders(root, res);
        return res;
    }
};

//维护一个栈，迭代法
class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        if (!root) return res;
        stack<Node*> s;
        s.push(root);
        while (!s.empty()) {
            Node *p = s.top();
            s.pop();
            res.push_back(p->val);
            for (int i = 0; i < p->children.size(); ++i) {
                if(p->children[i]) s.push(p->children[i]);
            }
        }
        reverse(res.begin(), res.end());//翻转数组
        return res;
    }
};