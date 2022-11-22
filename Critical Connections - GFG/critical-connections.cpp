//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:

	    // Code here
	     void dfs(int node, int parent, int& timer, vector<int>& tin, vector<int>& low, vector<int>& vis, vector<int> adj[], set<pair<int,int>>& res)
    {
        vis[node]=1;
        tin[node]=low[node]=timer++;
        for(auto it: adj[node])
        {
            if(it==parent) continue;
            if(!vis[it])
            {
                dfs(it,node,timer,tin,low,vis,adj,res);
                low[node]=min(low[node],low[it]);
                if(low[it]>tin[node])
                {
                    if(it>node) res.insert({node,it});
                    else res.insert({it,node});
                }
            }
            else
            {
                low[node]=min(low[node],tin[it]);
            }
        }
    }
	vector<vector<int>>criticalConnections(int n, vector<int> adj[])
	{
	    int timer=0; 
	    vector<int> tin(n,-1), low(n,-1), vis(n,0);
	    set<pair<int,int>> res;
	    for(int i=0; i<n; i++)
	    {
	        if(!vis[i])
	        {
	            dfs(i,-1,timer,tin,low,vis,adj,res);
	        }
	    }
	    vector<vector<int>> ans;
	    for(auto it: res)
	    {
	        ans.push_back({it.first,it.second});
	    }
	    return ans;
	}
	
};

//{ Driver Code Starts.

int main(){
	int tc;
    cin >> tc;
    while(tc--){
        int V, E;
        cin >> V >> E;
        vector<int>adj[V];
        for(int i = 0; i < E; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        vector<vector<int>>ans = obj.criticalConnections(V, adj);
        
        for(int i=0;i<ans.size();i++)
            cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    }
	return 0;
}
// } Driver Code Ends