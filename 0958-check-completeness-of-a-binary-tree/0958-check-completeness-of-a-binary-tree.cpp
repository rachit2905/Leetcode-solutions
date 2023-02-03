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
    bool isCompleteTree(TreeNode* root) {
       queue<TreeNode*> que;
        que.push(root);
        bool check=false;
        while(que.size()){
            int size=que.size();
            for(int i=0;i<size;i++){
                TreeNode* node=que.front();
                que.pop();
                if(node==NULL)
                    check=true;
                else{
                    if(check==true)
                        return false;
                    que.push(node->left);
                    que.push(node->right);
                }
            }
        }
        return true;}
};