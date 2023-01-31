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
    TreeNode* findinorder(TreeNode* root)
    {
        if(!root)return NULL;
        if(root->left==NULL)return root;
        return findinorder(root->left);
        
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)return root;
        if(root->val>key)
        {
            root->left=deleteNode(root->left,key);
        }
        else if(root->val<key)
        {
            root->right=deleteNode(root->right,key);
        }
        else
        {
            // if node is leaf node, then simply delete the node
            
            if(root -> left == NULL && root -> right == NULL)
            {
                delete root;
                
                return NULL;
            }
         else if(root -> left == NULL)
            {
                TreeNode* temp = root -> right;
                
                delete root;
                
                return temp;
            }
            
            // if node has only left subtree, delete the node and replace the node with left subtree
            
            else if(root -> right == NULL)
            {
                TreeNode* temp = root -> left;
                
                delete root;
                
                return temp;
            }
            else
            {
                  TreeNode* successor = findinorder(root -> right);
                
                // replace the node with inorder successor
                
                root -> val = successor -> val;
                
                // call deleteNode for deleting inorder successor
                
                root -> right = deleteNode(root -> right, successor -> val);
            }
            }
        return root;
    }
};