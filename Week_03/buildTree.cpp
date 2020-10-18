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
    unordered_map<int, int> index;
    TreeNode* mybuildTree(vector<int>& preorder, vector<int>& inorder, int pre_left, int pre_right, int in_left, int in_right) {
        if (pre_left > pre_right) {
            return nullptr;
        }
        int pre_root = pre_left;//先序序列最左边的下标为根结点
        int in_root = index[preorder[pre_root]];//寻找根结点在中序中的相应位置的下标
        TreeNode *root = new TreeNode(preorder[pre_root]);//创建一个根结点
        int size_left = in_root - in_left;//根据中序序列，得到左子树的元素长度
        root->left = mybuildTree(preorder, inorder, pre_left + 1, pre_left + size_left, in_left, in_root - 1);
        root->right = mybuildTree(preorder, inorder, pre_left + size_left + 1, pre_right, in_root + 1, in_right);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int len = preorder.size();
        for (int i = 0; i < len; ++i) {
            index[inorder[i]] = i;//key为中序序列元素，键值为对应下标
        }
        return mybuildTree(preorder, inorder, 0, len - 1, 0, len - 1);
    }
};