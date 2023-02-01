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
      vector<vector<int>> elements;

    void getEls(TreeNode * root, int level) {
        if (root == nullptr) return;
        vector<int> tmp;
        if (this->elements.size() <= level) this->elements.push_back(tmp);
        this->elements[level].push_back(root->val);
        getEls(root->right, level+1);
        getEls(root->left, level+1);
    }

    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        getEls(root, 0);
        for (auto vec : this->elements) {
            long int sum = 0;
            for (auto el : vec)
                sum += el;
            res.push_back((double)sum / (double)vec.size());
        }
        return res;
    }
};