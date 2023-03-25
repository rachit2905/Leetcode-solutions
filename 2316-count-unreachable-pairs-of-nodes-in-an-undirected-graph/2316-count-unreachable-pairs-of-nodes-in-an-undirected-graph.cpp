class Solution {
public:
    
    int co=1,co1=1;
    void dfs(int node,vector<int>&vis,vector<int>adj[])
    {
        vis[node]=1;
        for(auto it:adj[node])
        {
            if(!vis[it]){co++;co1++;dfs(it,vis,adj);}
        }
        return;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        long long ans=0;
        vector<int>vis(n,0);
        // for(auto it:adj)
        // {
        //     for(auto it1:it)
        //         cout<<it1<<" ";
        //     cout<<"\n";
        // }
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(i,vis,adj);
                if(i!=0)co++;
                ans+=(long long)(n-co)*(long long)co1;
            //cout<<co<<" "<<co1<<"\n";
                
                co1=1;
            }
        }
        return ans;
    }
};