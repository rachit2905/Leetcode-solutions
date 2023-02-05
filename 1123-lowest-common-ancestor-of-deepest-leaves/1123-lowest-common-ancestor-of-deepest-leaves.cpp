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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        queue<TreeNode*>q1;
        q1.push(root);
        TreeNode* fro;TreeNode*bac;
        while(!q1.empty())
        {
           int sz=q1.size();
            fro=q1.front();
             bac=q1.back();
            for(int i=0;i<sz;i++)
            {
                auto it=q1.front();
                q1.pop();
                if(it->left)q1.push(it->left);
                if(it->right)q1.push(it->right);
            }
        }
        return lca(root,fro,bac);
    }
    TreeNode* lca(TreeNode* root,TreeNode* n1,TreeNode* n2)
    {
        if(!root || root==n1  || root==n2)return root;
        TreeNode* left=lca(root->left,n1,n2);
        TreeNode* right=lca(root->right,n1,n2);
        if(!left)return right;
        else if(!right)return left;
        else return root;
    }
};