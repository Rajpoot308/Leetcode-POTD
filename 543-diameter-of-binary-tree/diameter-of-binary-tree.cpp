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
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;

        int dLeft = maxDepth(root -> left);
        int dRight = maxDepth(root -> right);

        int ans = max(dLeft, dRight) + 1;
        return ans;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;

        int dLeft = diameterOfBinaryTree(root -> left);
        int dRight = diameterOfBinaryTree(root -> right);

        int dRoot = maxDepth(root -> left) + maxDepth(root -> right);

        int ans = max(dLeft, max(dRight, dRoot));
        return ans;
    }
};