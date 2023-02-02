/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *};
 */
class Solution
{
    public:
        void helper(TreeNode *root, unordered_map<TreeNode*, TreeNode*> &m)
        {
            queue<TreeNode*> q;
            q.push(root);
            while (!q.empty())
            {
                auto node = q.front();
                q.pop();
                if (node->left)
                {
                    m[node->left] = node;
                    q.push(node->left);
                }
                if (node->right)
                {
                    m[node->right] = node;
                    q.push(node->right);
                }
            }
        }
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        unordered_map<TreeNode*, TreeNode*> m;
        helper(root, m);
        unordered_map<TreeNode*, bool> v;
        queue<TreeNode*> q;
        q.push(target);
        v[target] = true;
        int current_lev = 0;
        while (!q.empty())
        {
            int siz = q.size();
            if (current_lev == k) break;
            current_lev++;
            while (siz--)
            {
                auto node = q.front();
                q.pop();
                if (node->left && !v[node->left])
                {
                    v[node->left] = true;
                    q.push(node->left);
                }
                if (node->right && !v[node->right])
                {
                    v[node->right] = true;
                    q.push(node->right);
                }
                if (m[node] && !v[m[node]])
                {
                    v[m[node]] = true;
                    q.push(m[node]);
                }
            }
        }
        vector<int> res;
        while (!q.empty())
        {
            auto node = q.front();
            q.pop();
            res.push_back(node->val);
        }
        return res;
    }
};