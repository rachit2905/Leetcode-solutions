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
     int count=0;
    void helper(TreeNode *root, vector<int>v){
        if(root==NULL) return;
        v[root->val]++;
        if(root->left==NULL&&root->right==NULL){
            int odd_occurances=0;
            for(int i=0;i<v.size();i++){
                if(v[i]%2!=0){
                    odd_occurances++;
                }
            }
            if(odd_occurances<=1) count++;
            return;
        }
        helper(root->left,v);
        helper(root->right,v);
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int>v(10,0);
        helper(root,v);
        return count;
    }
};