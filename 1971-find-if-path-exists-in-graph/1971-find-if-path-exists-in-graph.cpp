class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int s, int d) {
        vector<int>adj[n];
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
             adj[it[1]].push_back(it[0]);
        }
        if(s==d)return true;
        queue<int>q1;
        q1.push(s);
        vector<bool>vis(n,0);
        vis[s]=1;
        while(!q1.empty())
        {
            int u=q1.front();
            q1.pop();
            for(auto it:adj[u])
            {
                if(it==d)return 1;
                else if(!vis[it])
                {
                    vis[it]=1;
                    q1.push(it);
                }
            }
        }
        return 0;
    }
};