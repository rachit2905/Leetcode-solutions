class Solution {
public:
    int dfs(int x,int y,vector<vector<int>>& grid,vector<vector<int>>&vis,int m,int n,int &temp)
    {
        if(x<0 || y<0 || x>m-1 || y>n-1 || vis[x][y] || grid[x][y]==0)
            return 0;
        temp++;
        vis[x][y]=1;
        dfs(x+1,y,grid,vis,m,n,temp);
        dfs(x-1,y,grid,vis,m,n,temp);
        dfs(x,y+1,grid,vis,m,n,temp);
        dfs(x,y-1,grid,vis,m,n,temp);
       // vis[x][y]=0;
        return temp;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    int temp=0;
                    ans=max(ans,dfs(i,j,grid,vis,m,n,temp));   
                }
            }
        }
        return ans;
    }
};