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
        bool isEvenOddTree(TreeNode *root)
        {
            int level = 0;
            queue<TreeNode*> q;
            q.push(root);

            while (!q.empty())
            {
                int n = q.size();
                int prev = (level % 2) ? INT_MAX : INT_MIN;
                for (int i = 0; i < n; ++i)
                {
                    TreeNode *curr = q.front();
                    q.pop();

                    if (level % 2 == curr->val % 2) return false;
                    if (level % 2)
                    {
                        if (curr->val >= prev)
                        {
                            return false;
                        }
                    }
                    if (!(level % 2) && curr->val <= prev) return false;

                    prev = curr->val;

                    if (curr->left)
                    {
                        q.push(curr->left);
                    }
                    if (curr->right)
                    {
                        q.push(curr->right);
                    }
                }
                ++level;
            }
            return true;
        }
};