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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root==NULL) return{};
        vector<vector<int>> ans;
        int itr = 0;
        queue<TreeNode*> q;
        
        q.push(root);
        while(!q.empty()){
            vector<int> level;
            int current_q_size = q.size();
            for(int i=0; i<current_q_size; i++){
            TreeNode* x = q.front();
            q.pop();
            level.push_back(x->val);
            if(x->left!=NULL) q.push(x->left);
            if(x->right!=NULL) q.push(x->right);
            }
            ans.push_back(level);
        }
        reverse(ans.begin(),ans.end());
        return ans;  
    }
};