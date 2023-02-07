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
    vector<int> sol(TreeNode* root , int d)
    {
        if(!root)
        return {0};
        if(root->left==NULL && root->right==NULL)
        return {1};
        auto l = sol(root->left,d);
        auto r = sol(root->right,d);
        for(auto a: l)
        {
            for(auto b: r)
            {
                if(a&&b&&(a+b)<=d)
                {
                    ans++;
                }
            }
        }

        vector<int> ret;
        for(auto it: l)
        {
            if(it && it+1<d)
            ret.push_back(it+1);
        }
        for(auto it: r)
        {
            if(it && it+1<d)
            ret.push_back(it+1);
        }


        return ret;
    }
    int countPairs(TreeNode* root, int distance) {
        
        sol(root,distance);
        return ans;
    }
};