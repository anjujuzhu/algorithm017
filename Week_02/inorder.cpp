#include<iostream>
#include<unordered_map>
#include<vector> 
#include<algorithm>
using namespace std;
//递归
//注意inorder的传参，vector<int>& res
class Solution {
public:
    void inorder(TreeNode* root, vector<int>& res) {
        if (!root) return;
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root, res);
        return res;
    }
};

//迭代
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    TreeNode* p = root;
    stack<TreeNode*> s;
    while (p || s.size()) {
        while (p) {
            s.push(p);
            p = p->left;
        }
        p = s.top();
        s.pop();
        res.push_back(p->val);
        p = p->right;
    }
    return res;
}

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode> s;
    TreeNode* p;
    s.push(root);
    while (s.empty()) {
        p = s.top();
        s.pop();
        res.push_back(p->val);
        if (root->left) s.push(root->left);
        if (root->right) s.push(root->left);
    }
    return res;
}