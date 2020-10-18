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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //一直向下深入，判断当前节点是否为p || q
        if (!root || root == p || root == q) {
            return root;
        }
        //检查p,q是否在左子树
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        //检查p,q是否在右子树
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        //如果都不为空，就返回根结点，就是最近公共组件
        if (left && right) return root;
        //否则，left不空为left，right不空为right
        return left ? left : right;
    }
};