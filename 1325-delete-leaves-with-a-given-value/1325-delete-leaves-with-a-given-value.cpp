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
    int target;
    TreeNode* solve(TreeNode* &root){
        //base case
        if(root==NULL)return NULL;
        
        root->left  = solve(root->left);
        root->right = solve(root->right);
        
        if(root->left==NULL && root->right==NULL && root->val==target)
            return NULL;
        return root;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        this->target = target;
        return solve(root);
    }
};