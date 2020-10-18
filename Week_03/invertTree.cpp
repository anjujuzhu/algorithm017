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
    void reverse(TreeNode* root) {
        if (!root) return;
        if (root->left || root->right) {
            TreeNode *tmp = root->left;
            root->left = root->right;
            root->right = tmp;
        }
        reverse(root->left);
        reverse(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        reverse(root);
        return root;
    }
};

TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr) {
        return nullptr;
    }
    TreeNode* left = invertTree(root->left);
    TreeNode* right = invertTree(root->right);
    root->left = right;
    root->right = left;
    return root;
}