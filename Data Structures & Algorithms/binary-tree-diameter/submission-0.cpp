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

class Solution {
public:
    int max_d = 0;

    int height(TreeNode* node){
        if (node == nullptr) return 0;

        int lH = height(node->left);
        int rH = height(node->right);
        max_d = max(max_d, lH+rH);

        return 1+max(lH, rH);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        max_d = 0;
        height(root);       
        return max_d;
    }

};
