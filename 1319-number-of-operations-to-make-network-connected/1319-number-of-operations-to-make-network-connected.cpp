class Solution {
public:
    int co=0;
    void dfs(int node,vector<int>adj[],vector<int>&vis)
    {
        vis[node]=1;
        for(auto it:adj[node])
        {
            if(!vis[it])dfs(it,adj,vis);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int>adj[n+1];
        
        for(int i=0;i<connections.size();i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        vector<int>vis(n,0);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
            dfs(i,adj,vis);
            co++;
            }
        }
        if(connections.size()>=n-1)
        return co-1;
        else return -1;
    }
};