/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
//BFS
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            int val = INT_MIN;
            while (size--) {
                TreeNode *tmp = q.front();
                q.pop();
                val = max(val, tmp->val);
                if (tmp->left) q.push(tmp->left);
                if (tmp->right) q.push(tmp->right);
            }
            res.push_back(val);
        }
        return res;
    }
};
//DFS
class Solution {
public:
    void dfs(TreeNode* root, vector<int>& res, int level) {
        if (!root) return;
        if (level >= res.size()) {
            res.push_back(INT_MIN);
        }
        res[level] = max(res[level], root->val);
        dfs(root->left, res, level + 1);
        dfs(root->right, res, level + 1);
    }
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        dfs(root, res, 0);
        return res;
    }
};