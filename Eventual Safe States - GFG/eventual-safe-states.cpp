//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool dfs(int s,  vector<int>&vis,  vector<int>&dfsvis,  vector<int>&cycle,vector<int> adj[])
    {
        vis[s]=dfsvis[s]=1;
        for(auto it:adj[s])
        {
            if(!vis[it])
            {
            if(dfs(it,vis,dfsvis,cycle,adj))return cycle[s]=1;;
            }
            else if(dfsvis[it])
            return cycle[s]=1;
            
        }
        dfsvis[s]=0;
        return 0;
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int>ans;
        vector<int>vis(V,0);
        
        vector<int>dfsvis(V,0);
        
        vector<int>cycle(V,0);
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            dfs(i,vis,dfsvis,cycle,adj);
        }
        for(int i=0;i<V;i++)
        {
            if(!cycle[i])ans.push_back(i);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends