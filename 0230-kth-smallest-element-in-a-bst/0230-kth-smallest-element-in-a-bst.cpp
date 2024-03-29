/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        vector<int> ans;
    void help(TreeNode *root)
    {
        if (!root) return;
        help(root->left);
        ans.push_back(root->val);
        help(root->right);
    }
    int kthSmallest(TreeNode *root, int k)
    {
        if (!root) return 0;
        help(root);
        return ans[k - 1];
    }
};