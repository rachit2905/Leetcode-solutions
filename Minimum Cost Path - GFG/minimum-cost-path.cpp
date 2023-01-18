//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        // Code here
         int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, 
        greater<pair<int,pair<int,int>>>> pq;
        pq.push({grid[0][0],{0,0}});
        visited[0][0] = true;
        int res = INT_MAX;
        while(!pq.empty())
        {
            auto p = pq.top();
            pq.pop();
            int i = p.second.first;
            int j = p.second.second;
            int c = p.first;
            if(i == n-1 && j == m-1 && res>c)
                res = c;
            int row[4] = {0,0,-1,1};
            int col[4] = {1,-1,0,0};
            for(int k=0;k<4;k++)
            {
                int u = i + row[k];
                int v = j + col[k];
                if(u>=0 && u<n && v>=0 && v<m && !visited[u][v])
                {
                    visited[u][v] = true;
                    pq.push({(c + grid[u][v]),{u,v}});
                }
            }
        }
        return res;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends