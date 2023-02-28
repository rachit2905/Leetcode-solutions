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
    vector<TreeNode*>ans;map<string,int>m1;
    string help(TreeNode* root)
    {
        if(!root)return "#";
        string s=help(root->left)+','+help(root->right)+','+to_string(root->val);
        m1[s]++;
        if(m1[s]==2)ans.push_back(root);return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        help(root);
        return ans;
    }
};