/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
   string serialize(TreeNode* root) {
        string str; 
        queue<TreeNode *> q;
        TreeNode *node;

        q.push(root);

        while(!q.empty()){
            node = q.front();
            q.pop();

            if(node == nullptr)
                str += "*#";
            else{
                str += to_string(node->val)+ "#";
                q.push(node->left);
                q.push(node->right);
            }
        }

        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        string token1, token2;
        queue<TreeNode *> q;
        TreeNode *root, *current;
        int start = 0, end;
        
        end = data.find('#', start);
        token1 = data.substr(start, end-start);
        if(token1 == "*")
            return nullptr;

        root = new TreeNode(stoi(token1));
        q.push(root);
        start = end+1;
        
        while(!q.empty()){
            current = q.front();
            q.pop();
            end = data.find('#', start);
            token1 = data.substr(start, end-start);
            start = end+1;
            end = data.find('#', start);
            token2 = data.substr(start, end-start);
            start = end+1;

            if(token1 == "*")
                current->left = nullptr;
            else{
                current->left = new TreeNode(stoi(token1));
                q.push(current->left);
            }

            if(token2 == "*")
                current->right = nullptr;
            else{
                current->right = new TreeNode(stoi(token2));
                q.push(current->right);
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));