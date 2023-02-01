/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root)return {};
        queue<Node*>q1;
        q1.push(root);
        vector<vector<int>>ans;
       // ans.push_back({root->val});
        while(!q1.empty())
        {
            vector<int>temp1;
            int sz=q1.size();
            for(int i=0;i<sz;i++)
            {
                Node* temp=q1.front();
                temp1.push_back(temp->val);
            q1.pop();
                for(auto it:temp->children)
                {
                    q1.push(it);
                }
            }
            ans.push_back(temp1);
        }
        return ans;
    }
};