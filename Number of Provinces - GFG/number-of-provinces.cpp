//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  void dfs(int i,vector<vector<int>> adj,vector<int>&vis)
  {
      vis[i]=1;
      for(int j=0;j<adj[0].size();j++)
      {
          if(j+1==i)continue;
          if(!vis[j+1] && adj[i-1][j]==1)
          dfs(j+1,adj,vis);
      }
  }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        int co=0;
        vector<int>vis(V+1,0);
        for(int i=1;i<=V;i++)
        {
            if(!vis[i])
            {
                co++;
                dfs(i,adj,vis);
            }
        }
        return co;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends