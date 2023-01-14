//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    vector<int> findOrder(int num, int m, vector<vector<int>> pre) 
    {
         vector<int>adj[num];
        for(int i=0;i<pre.size();i++)
        {
            int x=pre[i][0];
            int y=pre[i][1];
            adj[y].push_back(x);
            
        }
        vector<int>ind(num,0);
        for(int i=0;i<num;i++)
        {
            for(auto it:adj[i])
            {
                ind[it]++;
            }
        }
        queue<int>q1;
        for(int i=0;i<num;i++)
        {
            if(ind[i]==0)
                q1.push(i);
            
        }
        vector<int>ans;
        while(!q1.empty())
        {
            int x=q1.front();
            q1.pop();
            ans.push_back(x);
            for(auto it:adj[x])
            {
                ind[it]--;
                if(ind[it]==0)
                {
                    q1.push(it);
                }
                
            }
        }
        if(ans.size()!=num)
            return {};
        else return ans;
    }
    
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends