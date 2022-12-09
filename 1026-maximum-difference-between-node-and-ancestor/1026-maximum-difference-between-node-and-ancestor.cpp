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
     int ans=0;
    void util(TreeNode* r,int m,int mi)
    {
        if(!r)
        {
            ans=max(ans,m-mi);
            return;
        }
        m=max(m,r->val);
        mi=min(mi,r->val);
        util(r->left,m,mi);
        util(r->right,m,mi);
    }
    
    int maxAncestorDiff(TreeNode* root) {
        util(root,0,5001);
        return ans;
    }
};