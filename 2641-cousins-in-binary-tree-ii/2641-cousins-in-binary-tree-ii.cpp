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
    void help(TreeNode *root,vector<long long>&v2,int depth)
    {
        if(!root)return;
        root->val=v2[depth]-root->val;depth++;
        if(root->left)help(root->left,v2,depth);
        if(root->right)help(root->right,v2,depth);
        
    }
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(!root)return root;
        vector<vector<pair<int,int>>>v1;
        queue<pair<TreeNode*,int>>q1;
        q1.push({root,-1});
        while(!q1.empty())
        {
            vector<pair<int,int>>v2;
            int sz=q1.size();
            for(int i=0;i<sz;i++)
            {
                auto it=q1.front();
                q1.pop();
                v2.push_back({it.first->val-(it.second==-1?0:it.second),it.second});
                if(it.first->left!=NULL && it.first->right!=NULL){q1.push({it.first->left,it.first->right->val});
                                                                  int x=it.first->left->val;
                                              it.first->left->val+=it.first->right->val;                    
                q1.push({it.first->right,x});it.first->right->val+=x;}
                else if(it.first->left)q1.push({it.first->left,-1});
                else if(it.first->right)q1.push({it.first->right,-1});
            }
            v1.push_back(v2);
        }
        vector<long long>v2;
        for(auto it:v1)
        {
            long long int sum=0;
            for(auto it1:it)
            {
                sum+=(long long int)it1.first;
            }
            cout<<sum<<" ";
            v2.push_back(sum);
        }
        help(root,v2,0);
       return root;
    }
};