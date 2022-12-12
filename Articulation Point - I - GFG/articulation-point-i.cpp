//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void solve(int node,int parent,  unordered_map<int,bool>&vis,vector<int>&disc,vector<int>&low,vector<int> adj[],set<int>&result,int &time) 
  {
     vis[node]=true;
     disc[node]=low[node]=time++;int child=0;
     for(int nbr:adj[node])
     {
         if(nbr==parent)continue;
         else if(!vis[nbr])
         {
             solve(nbr,node,vis,disc,low,adj,result,time);
             low[node]=min(low[node],low[nbr]);
             if(low[nbr]>=disc[node] && parent!=-1)
             result.insert(node);
             child++;
         }
         else
         {
             low[node]=min(low[node],disc[nbr]);
         }
     }
     if(parent==-1 && child>1)
     result.insert(node);
  }
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here
        vector<int>disc(V,-1);
        vector<int>low(V,-1);
        unordered_map<int,bool>vis;int time=0;
        set<int>result;
        int parent=-1;
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            solve(i,parent,vis,disc,low,adj,result,time);
        }
        if(result.size()>0)
        {vector<int>v1;
           for(auto it:result)
           {
               v1.push_back(it);
           }return v1;
        }
        else return {-1};
        
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
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends