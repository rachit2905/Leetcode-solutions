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
   void paths(TreeNode* root, string curr_path, vector<string> &ans)
    {
        if(root==NULL)
        return;

        if(root->right==NULL and root->left==NULL)
        {
            curr_path=curr_path + (to_string(root->val));
            ans.push_back(curr_path);
            return;
        }

        curr_path+=to_string(root->val)+"->";
        paths(root->left,curr_path,ans);
        paths(root->right,curr_path,ans);
    }

    vector<string> binaryTreePaths(TreeNode* root) {

        vector<string> ans;

        string curr_path="";

        paths(root,curr_path,ans);

        return ans;
        
    }
};
