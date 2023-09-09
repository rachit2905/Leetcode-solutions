//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

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
            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

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
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function template for C++
/*
Structure of the node of the tree is as follows 
struct Node {
    struct Node* left, *right;
    int data;
};
*/

class Solution{
 
      Node* findlca(Node* root,int p,int q){
        if(root==NULL || p==root->data || q==root->data)return root;
        Node* left=findlca(root->left,p,q);
        Node* right=findlca(root->right,p,q);
        if(left==NULL)return right;
        if(right==NULL)return left;
        return root;
    }
    int solve(Node* lca,int root){
        queue<pair<int,pair<int,Node*>>>q;
        q.push({0,{0,lca}});
        while(!q.empty()){
            int sign=q.front().first;
            int steps=q.front().second.first;
            Node* node=q.front().second.second;
            q.pop();
            if(node->data==root)return steps;
            if(node->left){
                if(sign==2)q.push({1,{steps+1,node->left}});
                else q.push({1,{steps,node->left}});
            }
            if(node->right){
                if(sign==1)q.push({2,{steps+1,node->right}});
                else q.push({2,{steps,node->right}});
            }
        }
    }
  public:
    // function should return the number of turns required to go from first node to second node 
    int NumberOFTurns(struct Node* root, int first, int second)
    {
      Node* lca=findlca(root,first,second);
      int ans=solve(lca,first)+solve(lca,second);
      if(lca->data!=first &&   lca->data!=second)ans+=1;
      return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    struct Node *child;
    scanf("%d ", &t);
    while (t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        int turn, first, second;
        cin>>first>>second;
        Solution ob;
        if ((turn = ob.NumberOFTurns(root, first, second) ))
            cout<<turn<<endl;
        else 
            cout<<"-1\n";
        cin.ignore();
    }
    return 0;
}

// } Driver Code Ends