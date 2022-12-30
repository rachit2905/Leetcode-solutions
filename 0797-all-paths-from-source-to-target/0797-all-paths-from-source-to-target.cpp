class Solution {
    void f(vector<vector<int>>& adj, vector<vector<int>>& ans, vector<int>& ds, int node){
        if (node == adj.size()-1){
            ans.push_back(ds);
            return ;
        }
        for (auto i:adj[node]){
            ds.push_back(i);
            f(adj, ans, ds, i);
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> ds{0};
        vector<vector<int>> ans;
        f(graph, ans, ds, 0);
        return ans;
    }
};