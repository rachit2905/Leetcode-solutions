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
        vector<int> s1;
    void help(TreeNode *root)
    {
        if (!root) return;
        help(root->left);
        s1.push_back(root->val);
        help(root->right);
    }
    vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
    {
       	//vector < int>ans;
        help(root1);
        help(root2);
        sort(s1.begin(),s1.end());
        return s1;
    }
};