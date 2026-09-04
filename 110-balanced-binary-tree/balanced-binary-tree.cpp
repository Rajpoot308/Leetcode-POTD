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

// 2. T.C. O(n) S.C. O(h) 
    bool isBal = true;
    
    // bottom up recursion
    int findHeightBinaryTree(TreeNode* root) {
        // base case
        if(!root) return 0;

        // recursion
        int leftH = findHeightBinaryTree(root->left);
        int rightH = findHeightBinaryTree(root->right);

        if(isBal) {
            isBal = abs(leftH - rightH) <= 1;
        }

        return max(leftH, rightH) + 1;
    }
    bool isBalanced(TreeNode* root) {
        findHeightBinaryTree(root);
        return isBal;
    }
};