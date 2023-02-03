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
    
   vector<string>ans;
    void depth(TreeNode*root,string s){
        if(root==NULL){
            return;
        }
        s+=char(root->val+'a');
        if(root->left==NULL && root->right==NULL){
            reverse(s.begin(),s.end());
            ans.push_back(s);
        }
        depth(root->left,s);
        depth(root->right,s);
    }
    string smallestFromLeaf(TreeNode* root) {
       string s;
       depth(root,s);
       sort(ans.begin(),ans.end());
        return ans[0];
    }
};