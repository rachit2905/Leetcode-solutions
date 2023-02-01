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
    int widthOfBinaryTree(TreeNode* root) {
        if(root->left==NULL&&root->right==NULL) return 1;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0}); 
        int res=1;
        while(!q.empty())
        {
            int size=q.size();
            int minind=q.front().second;
            int first,last;
                first=q.front().second;
                last=q.back().second;
            res=max(res,last-first+1);
            for(int i=0;i<size;i++)
            {
                TreeNode *curr=q.front().first;
                long cur_id=q.front().second-minind;
                q.pop();
                
                if(curr->left!=NULL) 
                q.push({curr->left,2*cur_id+1});
                if(curr->right!=NULL) 
                q.push({curr->right,2*cur_id+2});
            }
        }
        return res;
    }

};