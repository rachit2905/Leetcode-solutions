class Solution {
public:
    void dfs(int s, vector<pair<int, int>> adj[], int &ans, vector<int> &vis) {
        if (vis[s]) return;
        vis[s]=true;
        for (auto c: adj[s]) {
            ans =  min(ans, c.second);
            dfs(c.first, adj, ans, vis);
        }
    }
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<pair<int, int>> adj[n+1];
        for (auto &i: roads) {
            adj[i[0]].push_back({i[1], i[2]});
            adj[i[1]].push_back({i[0], i[2]});
        }
        vector<int> vis(n+1, false);
        int ans = INT_MAX;
        dfs(1, adj, ans, vis);
        return ans;
    }

};