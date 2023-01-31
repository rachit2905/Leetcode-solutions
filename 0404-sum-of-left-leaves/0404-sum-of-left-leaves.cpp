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
    void sumLL(TreeNode* root,int &sum,int flag)
    {
        if(root==NULL)
            return ;
        if(!root->left&&!root->right)
        {
            if(flag==0)
                sum+=root->val;
        
        }
        sumLL(root->left,sum,0);
        sumLL(root->right,sum,1);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        
        int sum=0;
        sumLL(root,sum,-1);
        return sum;
    }
};
