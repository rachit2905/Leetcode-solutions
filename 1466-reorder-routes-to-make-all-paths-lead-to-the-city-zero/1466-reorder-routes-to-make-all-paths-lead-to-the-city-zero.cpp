class Solution {
public:
    int minReorder(int n, vector<vector<int>>& conn) {
         vector<bool> visited(n,false);
        unordered_map<int,vector<pair<int,int>>> adj;

        for(auto v : conn){
            adj[v[0]].push_back({v[1],1});
            adj[v[1]].push_back({v[0],0});
        }

        queue<int> q;
        q.push(0);
        visited[0] = true;
        int ans = 0;
        while(!q.empty()){
            int top = q.front();
            q.pop();

            for(auto p : adj[top]){
                if(visited[p.first] == false){
                    visited[p.first] = true;
                    ans += p.second;
                    q.push(p.first);
                }
            }
        }
        
        return ans;
    }
};