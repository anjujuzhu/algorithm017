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
    bool estimate(TreeNode* root, long long lower, long long upper) {
        if (root == nullptr) {
            return true;
        }
        if (root->val <= lower || root->val >= upper) {
            return false;
        }
        return estimate(root->left, lower, root->val) && estimate(root->right, root->val, upper);
    }
    bool isValidBST(TreeNode* root) {
        return estimate(root, LONG_MIN, LONG_MAX);
    }
};