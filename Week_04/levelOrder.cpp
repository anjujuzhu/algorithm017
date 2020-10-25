/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> tmp;
            while (size--){
                TreeNode *node = q.front();
                q.pop();
                tmp.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            res.push_back(tmp);
        }
        return res;
    }
};

//dfs
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        dfs(root, res, 0);
        return res;
    }
    void dfs(TreeNode* root, vector<vector<int>>& res, int level) {
        if (!root) return;
        if (level >= res.size()) {
            res.push_back(vector<int>());
        }
        res[level].push_back(root->val);
        dfs(root->left, res, level + 1);
        dfs(root->right, res, level + 1);
    }
};