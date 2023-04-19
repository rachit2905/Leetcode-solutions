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
    int ans = 0;
    void right(TreeNode* root, int count) {
        ans = max(ans, count);
        if (!root) return;
        right(root -> right, 0);
        left(root -> left, count + 1);
    }
    
    void left(TreeNode* root, int count) {
        ans = max(ans, count);
        if (!root) return;
        left(root -> left, 0);
        right(root -> right, count + 1);
    }
    
    int longestZigZag(TreeNode* root) {
        right(root -> right, 0);
        left(root -> left, 0);
        return ans;
    }
};