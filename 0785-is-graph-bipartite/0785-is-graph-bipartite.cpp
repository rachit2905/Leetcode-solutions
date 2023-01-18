class Solution {
public:
    vector<int>vis;
    vector<int>col;
    bool dfs(int node,vector<vector<int>>& adj,int c)
    {
        vis[node]=1;
        col[node]=c;
        for(auto it:adj[node])
        {
            if(vis[it]==0)
            {
                if(!dfs(it,adj,c^1))return false;
            }
            else
            {
                if(col[node]==col[it])
                    return false;
            }
        }
        return 1;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vis.resize(n);
        col.resize(n);
        for(int i=0;i<graph.size();i++)
        {
            if(vis[i]==0 && !dfs(i,graph,0))
                return 0;
        }
        return 1;
    }
};