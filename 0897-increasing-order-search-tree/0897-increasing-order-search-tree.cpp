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
    vector<int>in;
    
    void help(TreeNode* root){
        if(!root)return;
        help(root->left);
        in.push_back(root->val);
        help(root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        if(!root)return root;
        help(root);
        int co=1;
        TreeNode* root1=new TreeNode(in[0]);
        TreeNode* temp1=root1;
        while(co<in.size())
        {
            temp1->right=new TreeNode(in[co]);
            temp1=temp1->right;
            co++;
        }
        return root1;
    }
};