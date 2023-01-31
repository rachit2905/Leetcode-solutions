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
    vector<int> largestValues(TreeNode* root) {
        vector<int>ans;
        if(!root)return {};
        ans.push_back(root->val);
        queue<TreeNode*>q1;
        q1.push(root);
        while(!q1.empty())
        {
            vector<int>temp;
            int sz=q1.size();
            for(int i=0;i<sz;i++)
            {
                TreeNode* it=q1.front();
                q1.pop();
                if(it->left!=NULL){q1.push(it->left);temp.push_back(it->left->val);}
                if(it->right!=NULL){q1.push(it->right);temp.push_back(it->right->val);}
            }
            sort(temp.begin(),temp.end());
            if(temp.size()>0)
            ans.push_back(temp[temp.size()-1]);
        }
        return ans;
    }
};