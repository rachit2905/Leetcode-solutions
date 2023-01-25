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
    TreeNode* x = NULL, *y = NULL, *pred = NULL;

  void swap(TreeNode* a, TreeNode* b) {
    int tmp = a->val;
    a->val = b->val;
    b->val = tmp;
  }

  void findTwoSwapped(TreeNode* root) {
    if (root == NULL) return;
    findTwoSwapped(root->left);
    if (pred != NULL && root->val < pred->val) {
      y = root;
      if (x == NULL) x = pred;
      else return;
    }
    pred = root;
    findTwoSwapped(root->right);
  }
    void recoverTree(TreeNode* root) {
       findTwoSwapped(root);
    swap(x, y); 
    }
};
