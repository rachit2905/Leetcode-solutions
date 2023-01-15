class Solution {
public:
    void dfs(int node,int parent,vector<int>adj[],vector<int>&vis)
    {
        vis[node]=1;
        for(auto it:adj[node])
        {
            if(it==parent)continue;
            if(!vis[it])
            {
                dfs(it,node,adj,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>adj[n+1];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j])
                {
                    adj[i+1].push_back(j+1);
                    adj[j+1].push_back(i+1);
                }
            }
        }
        vector<int>vis(n+1,0);int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                dfs(i,-1,adj,vis);
                ans++;
            }
        }
        return ans;
    }
};