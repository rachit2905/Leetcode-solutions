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
    
   string ans = "";
    void solve(TreeNode *root, string temp)
    {
        temp += root->val + 'a';

        if (!root->left and !root->right)
        {
            reverse(temp.begin(), temp.end());

            if (ans == "" or temp < ans)
                ans = temp;

            return;
        }

        if (root->left)
            solve(root->left, temp);

        if (root->right)
            solve(root->right, temp);
    }

    string smallestFromLeaf(TreeNode *root)
    {
        string temp = "";
        solve(root, temp);

        return ans;
    }
};