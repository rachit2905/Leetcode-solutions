//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/*
// node structure:

struct Node
{
    int data;
    Node* left;
    Node* right;
};

*/



class Solution{

    public:
    void make_parents(Node *root, int home, unordered_map<Node *, Node *> &parent, Node *&bheem) {
        if(!root) return;
        
        queue<Node *> q;
        q.push(root);
        
        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            
            if(p->data == home) bheem = p;
            
            if(p->left) {
                parent[p->left] = p;
                q.push(p->left);
            }
            
            if(p->right) {
                parent[p->right] = p;
                q.push(p->right);
            }
        }
        
    }
public:
    int ladoos(Node* root, int home, int k) {
        if(!root) 
            return 0;
        
        unordered_map<Node *, Node *> parent;
        Node *bheem = NULL;
        make_parents(root, home, parent, bheem);
        
        queue<Node *> q;
        unordered_map<Node *, bool> visited;
        
        q.push(bheem);
        visited[bheem] = true;
        
        int sum = bheem->data, curr_lvl = 0;
        
        while(!q.empty()) {
            int n = q.size();
            if(curr_lvl == k) return sum;
            
            for(int i = 0; i < n; i++) {
                auto p = q.front();
                q.pop();
                
                if(p->left and !visited[p->left]) {
                    sum += p->left->data;
                    q.push(p->left);
                    visited[p->left] = true;
                }
                
                if(p->right and !visited[p->right]) {
                    sum += p->right->data;
                    q.push(p->right);
                    visited[p->right] = true;
                }
                
                if(parent[p] and !visited[parent[p]]) {
                    sum += parent[p]->data;
                    q.push(parent[p]);
                    visited[parent[p]] = true;
                }
            }
            
            curr_lvl++;
        }
        
        return sum;
    }


};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    getchar();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        
        int home,k;
        cin>> home >> k;
        getchar();
        Solution obj;
        cout<< obj.ladoos(root,home,k) << endl;
    }
	return 0;
}


// } Driver Code Ends