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
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*>q1;
        q1.push(root);int sum=0;
        while(!q1.empty())
        {
             sum=0;
            int sz=q1.size();
            for(int i=0;i<sz;i++)
            {
                auto it=q1.front();
                q1.pop();
                sum+=it->val;
                if(it->left)q1.push(it->left);
                if(it->right)q1.push(it->right);
            }
        }
        return sum;
    }
};