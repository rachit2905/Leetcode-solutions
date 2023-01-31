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
       if(!root) return "";

        string ans;
        queue<TreeNode *>q;
        q.push(root);

        while(!q.empty()) {
            auto p = q.front();
            q.pop();

            if(!p){
                ans.append("#,");
                continue;
            }
            
            q.push(p->left);
            q.push(p->right);

            ans.append(to_string(p->val) + ",");
        }

        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return NULL;

        stringstream s(data);
        string str;
        getline(s, str, ',');
        TreeNode *root = new TreeNode(stoi(str));
        
        queue<TreeNode *>q;
        q.push(root);

        while(!q.empty()) {
            auto p = q.front();
            q.pop();

            getline(s,str,',');
            if(str == "#") p->left = NULL;
            else {
                p->left = new TreeNode(stoi(str));
                q.push(p->left);
            }

            getline(s,str,',');
            if(str == "#") p->right = NULL;
            else {
                p->right = new TreeNode(stoi(str));
                q.push(p->right);
            }
        }

        return root;
    }
};
// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;