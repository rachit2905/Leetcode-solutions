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
        TreeNode* subtreeWithAllDeepest(TreeNode *root)
        {
            queue<TreeNode*> q1;
            q1.push(root);
            TreeNode *fro = q1.front();
            TreeNode *bac = q1.back();
            while (!q1.empty())
            {
                fro = q1.front();
                bac = q1.back();
                int sz = q1.size();
                for (int i = 0; i < sz; i++)
                {
                    auto it = q1.front();
                    q1.pop();
                    if (it->left) q1.push(it->left);
                    if (it->right) q1.push(it->right);
                }
            }
            return lca(root, fro, bac);
        }
    TreeNode* lca(TreeNode *root, TreeNode *n1, TreeNode *n2)
    {
        if (!root || root == n1 || root == n2) return root;
        auto it = lca(root->left, n1, n2);
        auto it1 = lca(root->right, n1, n2);
        if (it == NULL) return it1;
        else if (it1 == NULL) return it;
        else return root;
    }
};