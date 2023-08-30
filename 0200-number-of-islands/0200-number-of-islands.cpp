class Solution
{
    public:
        void help(int x, int y, vector<vector < char>> &grid, vector< vector< int>> &vis, int m, int n)
        {
            if (x > m - 1 || y > n - 1 || x < 0 || y < 0)
                return;
            if (grid[x][y] == '0' || vis[x][y]) return;
            vis[x][y] = 1;
            help(x + 1, y, grid, vis, m, n);
            help(x - 1, y, grid, vis, m, n);
            help(x, y + 1, grid, vis, m, n);
            help(x, y - 1, grid, vis, m, n);
        }
    int numIslands(vector<vector < char>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;

        vector<vector < int>> vis(m, vector<int> (n, 0));
        
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if ( grid[i][j] == '1' && !vis[i][j]){help(i,j,grid,vis,m,n); ans++;}
            }
        }
        return ans;
    }
};