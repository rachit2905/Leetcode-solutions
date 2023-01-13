class Solution {
public:
    bool dfs(int node,vector<int>adj[],vector<bool>&vis,vector<bool>&dfsvis)
    {
        vis[node]=1;
        dfsvis[node]=1;
        for(auto it:adj[node])
        {
            if(vis[it]==0)
            {
                if(dfs(it,adj,vis,dfsvis))return 1;
            }
            else if(dfsvis[it]==1)return 1;
        }
        dfsvis[node]=0;return 0;
    }
    bool canFinish(int n, vector<vector<int>>& ps) {
        vector<int>adj[n];
        for(int i=0;i<ps.size();i++)
        {
            adj[ps[i][1]].push_back(ps[i][0]);
        }
        vector<bool>vis(n,0);
        vector<bool>dfsvis(n,0);
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
            if(dfs(i,adj,vis,dfsvis))return false;}
        }
        return true;
    }
};