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
    
    int height(TreeNode *root){
        if(root == nullptr){
            return 0;
        }

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        int ans = max(leftHeight, rightHeight) + 1;

        return ans;
    }
    bool isBalanced(TreeNode* root) {
        if(root == nullptr){
            return true;
        }

        //one case
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        int diff = abs(leftHeight - rightHeight);

        bool ans1 = (diff <= 1);

        // recursion
        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);

        if(left && right && ans1){
            return true;
        }
        return false;
    }
};