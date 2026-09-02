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

    bool solve(TreeNode* root, long long int uL, long long int lL) {
        // nullptr is a valid BST
        if(!root) return true;
        // if(!root->left && !root->right) return true;

        // check for the current node
       
        if(root->val >= uL || root->val <= lL) return false;

        bool left = solve(root->left, root->val, lL);
        bool right = solve(root->right, uL, root->val);

        return left && right;
    }
    bool isValidBST(TreeNode* root) {
        long long int upperLimit = INT_MAX;
        long long int lowerLimit = INT_MIN;

        // if(!root->left && !root->right) return true;
        bool isValid = solve(root, upperLimit+1LL, lowerLimit-1LL);

        return isValid;
    }
};