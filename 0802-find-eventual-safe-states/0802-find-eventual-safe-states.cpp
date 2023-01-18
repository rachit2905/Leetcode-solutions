class Solution {
public:
    bool dfs(int s, vector<int>&vis,vector<int>&dfsvis, vector<int>&cycle,vector<vector<int>>& graph)
    {
        vis[s]=1;
        dfsvis[s]=1;
        for(auto it:graph[s])
        {
            if(!vis[it])
            {
                if(dfs(it,vis,dfsvis,cycle,graph))
                    return cycle[s]=1;
            }
            if(dfsvis[it])
                return cycle[s]=1;
        }
        dfsvis[s]=0;
        return 0;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>ans;
        int n=graph.size();
        vector<int>vis(n,0);
        vector<int>dfsvis(n,0);
        vector<int>cycle(n,0);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
                dfs(i,vis,dfsvis,cycle,graph);
        }
        for(int i=0;i<n;i++)
        {
            if(!cycle[i])
                ans.push_back(i);
        }
        return ans;
    }
};