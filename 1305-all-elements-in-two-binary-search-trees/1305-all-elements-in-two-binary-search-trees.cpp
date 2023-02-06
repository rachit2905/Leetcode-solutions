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
    multiset<int>s1;
    void help(TreeNode* root)
    {
        if(!root)return;
        help(root->left);
        s1.insert(root->val);
        help(root->right);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
         vector<int>ans;
        help(root1);
        help(root2);
        for(auto it:s1)
        {
            ans.push_back(it);
        }
        return ans;
    }
};