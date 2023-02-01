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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
       if(depth==1)
        {
            TreeNode* no=new TreeNode(val);
            no->left=root;
            return no;
        }
        int level=1;
        queue<TreeNode*> q1;
        q1.push(root);
        while(!q1.empty())
        {
            int sz=q1.size();
            while(sz--)
            {
                    TreeNode* curr=q1.front();
                    q1.pop();
            if(level==depth-1)
            {
                
                    TreeNode* l=curr->left;
                    TreeNode* r=curr->right;
                    curr->left=new TreeNode(val);
                    curr->right=new TreeNode(val);
                    curr->left->left=l;
                    curr->right->right=r;
                
            }
                if(curr->left)q1.push(curr->left);
                if(curr->right)q1.push(curr->right);
                
            }
            level++;
        }
        return root;
    }
};