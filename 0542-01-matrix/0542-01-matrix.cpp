class Solution {
public:
      vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m,vector<int> (n,0));
        vector<vector<int>> ans(m,vector<int> (n,0));
        queue<pair<pair<int,int>,int>> q;    //{row,col},dist
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 0){
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
            }
        }
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        while(!q.empty()){
            auto it = q.front();
            int row = it.first.first;
            int col = it.first.second;
            int dist = it.second;
            q.pop();
            ans[row][col] = dist;
            for(int i=0;i<4;i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !vis[nrow][ncol]){
                    q.push({{nrow,ncol},dist+1});
                    vis[nrow][ncol] = 1;
                }
            }
        }
        return ans;
    }
};