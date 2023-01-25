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
    vector<TreeNode*> generateTreesUtils(int l, int r)
    {
        vector<TreeNode*> res;
        if(l > r) 
        {
           res.push_back(NULL);
           return res;
        }

        for(int i = l; i <= r; i++)
        {
            vector<TreeNode*> left  = generateTreesUtils(l, i - 1);
            vector<TreeNode*> right = generateTreesUtils(i + 1, r);

            for(int j = 0; j < left.size(); j++)
            {
                for(int k =0; k < right.size(); k++)
                {
                    TreeNode* newNode = new TreeNode(i);
                    newNode->left = left[j];
                    newNode->right = right[k];

                    res.push_back(newNode);
                }
            }
        }
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        return generateTreesUtils(1, n);
    }
};
