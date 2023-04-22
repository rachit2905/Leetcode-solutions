/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)return root;
        queue<Node*>q1;
        q1.push(root);
       // root->next=NULL;
        while(!q1.empty())
        {
            int sz=q1.size();
            for(int i=0;i<sz-1;i++)
            {
                auto it=q1.front();
                q1.pop();
                it->next=q1.front();
                if(it->left)q1.push(it->left);
                if(it->right)q1.push(it->right);
            }
            auto it=q1.front();
            if(it->left)q1.push(it->left);
            if(it->right)q1.push(it->right);
            q1.pop();
            it->next=NULL;
        }
        return root;
    }
};