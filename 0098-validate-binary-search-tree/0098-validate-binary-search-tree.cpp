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
    bool validate(TreeNode* root, TreeNode* min, TreeNode* max) {
        // Empty trees are valid BSTs.
        if (!root) {
            return true;
        }

        // The current node's value must be between low and high.
        if ((min && root->val <= min->val) or
            ( max and root->val >= max->val)) {
            return false;
        }

        // The left and right subtree must also be valid.
             return  validate(root->right, root, max) &&
               validate(root->left, min, root);
    }

    bool isValidBST(TreeNode* root) {
        return validate(root, NULL, NULL);
    }
};