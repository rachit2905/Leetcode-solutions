class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
         vector<int>adj[n];
        for(int i=0;i<roads.size();i++){
            int u=roads[i][0],v=roads[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int maxres=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++)
            {
                int diff=adj[i].size()+adj[j].size();
          if(find(adj[i].begin(),adj[i].end(),j)!=adj[i].end())
              diff-=1;
                maxres=max(maxres,diff);
            }
        }
        return maxres;
    }
};