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

     // support variables
    vector<vector<TreeNode*>> paths;
    vector<TreeNode*> tmp;
    // DFSing the deepest paths
    void dfs(TreeNode* root) {
        // updating tmp
        tmp.push_back(root);
        // if tmp is the new deepest, we overwrite paths
        if (paths.empty() || tmp.size() > paths.back().size()) paths = {tmp};
        // if tmp is as deep as the last element in paths, we add it
        else if (tmp.size() == paths.back().size()) paths.push_back(tmp);
        // recursive calls to the children, if any
        if (root->left) dfs(root->left);
        if (root->right) dfs(root->right);
        // backtracking on tmp
        tmp.pop_back();
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        // extracting the longest paths
        dfs(root);
        // reducing the 2 extreme paths to the common node
        while (paths.front().back() != paths.back().back()) paths.front().pop_back(), paths.back().pop_back();
        return paths.front().back();
    }
};