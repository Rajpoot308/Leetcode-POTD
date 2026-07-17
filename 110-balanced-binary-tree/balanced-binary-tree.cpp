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

    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        
        int dLeft = maxDepth(root -> left);
        int dRight = maxDepth(root -> right);

        bool curr = abs(dLeft - dRight) <= 1;

        bool left = isBalanced(root -> left);
        bool right = isBalanced(root -> right);

        return curr && left && right;

    }
};