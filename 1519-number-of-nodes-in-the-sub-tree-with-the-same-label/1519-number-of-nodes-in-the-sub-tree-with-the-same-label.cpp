class Solution
{
    public:
    vector<int>ans;
        vector<int> help(int node, int parent, vector<int> adj[], string &labels)
        {
            int co = 0;
            vector<int> freq(26, 0);
            ++freq[labels[node] - 'a'];

            for (auto it: adj[node])
            {
                if (it == parent) continue;
                vector<int> temp = help(it, node, adj, labels);
                for(int i=0;i<26;i++)freq[i]+=temp[i];
            }
            ans[node]=freq[labels[node]-'a'];
            return freq;
        }
    vector<int> countSubTrees(int n, vector<vector < int>> &edges, string labels)
    {
        ans.resize(n,0);
        vector<int> adj[n];
        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);

            adj[edges[i][1]].push_back(edges[i][0]);
        }
        help(0, -1, adj, labels);
        return ans;
    }
};