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
    vector<TreeNode*> solve(int n){
        //base case
        if(n==1)return {new TreeNode() };
        vector<TreeNode*> ans;
        for(int i=1;i<n;i+=2){
            vector<TreeNode*> left  = solve(i);
            vector<TreeNode*> right = solve(n-i-1);
            for(auto l:left){
                for(auto r:right){
                    ans.push_back(new TreeNode(0,l,r));
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n%2==0)return {};
        return solve(n);
    }
};