//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int su(Node *root)
    {
         if(!root)return 0;
         if(!root->left && !root->right)return root->data;
         int le=su(root->left);
         int re=su(root->right);
         if(!le)return root->data+re;
         else if(!re)return root->data+le;
         return root->data+min(le,re);
    }
    int maxDifferenceBST(Node *root,int target){
        // Code here
        Node*temp=root;
        int sum=0;int find=0;
        while(temp)
        {
            if(temp->data!=target)
            {
                sum+=temp->data;
                if(temp->data>target)
                temp=temp->left;
                else temp=temp->right;
            }
            else
            {
                find=1;break;
            }
        }
        if(!find)return -1;
        if(!temp->left)return sum-su(temp->right);
        else if(!temp->right)return sum-su(temp->left);
        else return sum-min(su(temp->left),su(temp->right));
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int target;
        cin >> target;
        Solution ob;
        cout << ob.maxDifferenceBST(root, target);
        cout << endl;
    }
}
// } Driver Code Ends