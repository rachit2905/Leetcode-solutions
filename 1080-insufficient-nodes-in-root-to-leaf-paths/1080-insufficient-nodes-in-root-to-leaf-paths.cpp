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
    bool ans_(TreeNode* root, int sum, int& limit)
    {
        sum += root -> val;
        if(root -> left == nullptr && root -> right == nullptr)
            return sum >= limit;
        
        bool left = false, right = false;
        if(root -> left)
            left = ans_(root -> left, sum, limit);
        if(root -> right)
            right = ans_(root -> right, sum, limit);
        
        if(!left)
            root -> left = nullptr;
        if(!right)
            root -> right = nullptr;
        return left || right;
    }
//public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        if(ans_(root, 0, limit))
            return root;
        return nullptr;
    }
};