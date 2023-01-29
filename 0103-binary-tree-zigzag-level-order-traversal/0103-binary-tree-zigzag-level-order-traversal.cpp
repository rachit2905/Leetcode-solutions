/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *   int val;
 *   TreeNode * left;
 *   TreeNode * right;
 *   TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        vector<vector < int>> zigzagLevelOrder(TreeNode *root)
        {
           int count=0;
         vector<vector<int>>ans;
        if(root==nullptr)
        {
          return ans;
        }
        queue<TreeNode*>q;
        q.push(root);
        int size=0;
        while(!q.empty())
        {
            vector<int>nums;
            size=q.size();
            while(size--)
            {
                TreeNode* temp=q.front();
                 q.pop();
                nums.push_back(temp->val);
                if(temp->left!=nullptr)
                {
                 q.push(temp->left);
                }
                if(temp->right!=nullptr)
                {
                 q.push(temp->right);
                }
            }
            if(count%2==1)
            {
                reverse(nums.begin(),nums.end());
            }
            ans.push_back(nums);
            count++;
        }
        return ans;
    }
        
};