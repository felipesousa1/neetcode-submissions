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
    TreeNode* findLCA(TreeNode* node, int p, int q){
        if (node == nullptr) return nullptr;
        if (node->val < p) return findLCA(node->right, p, q);
        if (node->val > q) return findLCA(node->left, p, q);
        return node;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int pM = min(p->val, q->val);
        int qM = max(p->val, q->val);
        return findLCA(root, pM, qM);
    }
};
