class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int>adj[n+1];vector<bool>vis(n+1,false);
        for(int i=0;i<dislikes.size();i++)
        {
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
            
        }
        vector<int>color(n+1,-1);
        queue<int>q1;
        q1.push(1);
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                q1.push(i);
        while(!q1.empty())
        {
            int u=q1.front();
            q1.pop();
            if(vis[u])continue;
            vis[u]=true;
            for(auto it:adj[u])
            {
                if(color[it]==-1)
                {
                    color[it]=1-color[u];
                    q1.push(it);
                }
                else if(color[it]==color[u])return 0;
            }
        }
            }
        }
        return 1;
    }
};