class Solution
{
    public:
    void dfs(int x,int y,vector<vector<int>> &grid,int m,int n,vector<vector<int>> &vis)
    {
        if(x<0 || y<0 || x>=m || y>=n || vis[x][y] || grid[x][y]==0)
            return ;
        vis[x][y]=1;
        dfs(x+1,y,grid,m,n,vis);
        dfs(x-1,y,grid,m,n,vis);
        dfs(x,y+1,grid,m,n,vis);
        dfs(x,y-1,grid,m,n,vis);
    }
        int numEnclaves(vector<vector<int>> &grid)
        {
            int m = grid.size();
            int n = grid[0].size();
            vector<vector<int>>vis(m,vector<int>(n,0));
            for(int i=0;i<m;i++)
            {
               dfs(i,0,grid,m,n,vis);
                dfs(i,n-1,grid,m,n,vis);
                
            }
            for(int i=0;i<n;i++)
            {
                dfs(0,i,grid,m,n,vis);
                dfs(m-1,i,grid,m,n,vis);
            }
            int co=0;
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(!vis[i][j] && grid[i][j]==1)
                        co++;
                }
            }
            return co;
        }
};