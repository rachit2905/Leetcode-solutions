/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        TreeNode* bstFromPreorder(vector<int> &preorder)
        {
            if (preorder.empty())
                return nullptr;
            TreeNode *node, *curr, *root = new TreeNode(preorder[0]);
            stack<TreeNode*> st;
            st.push(root);
            for (int i = 1; i < preorder.size(); ++i)
            {
                int val = preorder[i];
                if (val < st.top()->val)
                {
                    node = new TreeNode(val);
                    st.top()->left = node;
                    st.push(node);
                }
                else
                {
                    do {
                        curr = st.top();
                        st.pop();
                    } while (!st.empty() && st.top()->val < val);
                    curr->right = new TreeNode(val);
                    st.push(curr->right);
                }
            }
            return root;
        }
};