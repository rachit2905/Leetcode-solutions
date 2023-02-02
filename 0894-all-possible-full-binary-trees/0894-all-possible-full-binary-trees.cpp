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
    vector<TreeNode*> allPossibleFBT(int n) {
         vector<TreeNode*>t;
        if(n%2==0)
            return t;
        vector<vector<TreeNode*>>v(n+1);
        v[0].push_back(NULL);
        v[1].push_back(new TreeNode());
        for(int i=3;i<n+1;i+=2){
            for(int j=1,k=i-2;k>0;j+=2,k-=2){
                for(auto x:v[j]){
                    for(auto y:v[k]){
                        v[i].push_back(new TreeNode(0,x,y));
                    }
                }
            }
        }
        return v[n];
    }
};