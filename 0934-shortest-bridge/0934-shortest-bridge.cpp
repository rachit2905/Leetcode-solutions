class Solution {
public:
    int m,n;
    queue<pair<int,int>>q1;
    void dfs(int x,int y,vector<vector<int>>& grid,vector<vector<int>>& vis)
    {
        if(x<0 || y<0 || x>=m || y>=n || vis[x][y]==1)
            return;
        
        vis[x][y]=1;
         if(grid[x][y]==0)
         {
            q1.push({x,y});
         return;}
        dfs(x+1,y,grid,vis);
        dfs(x,y-1,grid,vis);
        dfs(x-1,y,grid,vis);
        dfs(x,y+1,grid,vis);
            
    }
    int shortestBridge(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        int flag=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    dfs(i,j,grid,vis);flag=1;break;
                }
            }
            if(flag)break;
        }
        int level=0;
        vector<int>rowDir = {-1,1,0,0};
        vector<int>colDir = {0,0,-1,1};
        while(!q1.empty())
        {
            int size=q1.size();
            while(size--)
            {   
                int curRow = q1.front().first;
                int curCol = q1.front().second;
                if(grid[curRow][curCol]==1)return level;
                q1.pop();
                for(int i=0;i<4;i++)
                {
                    int nextRow= curRow+rowDir[i];
                    int nextCol= curCol+colDir[i];
                    if(nextRow>=0 && nextCol>=0 &&nextCol<n && nextRow<m && !vis[nextRow][nextCol])
                    {
                        vis[nextRow][nextCol]=1;
                        q1.push({nextRow,nextCol});
                    }
                }
                
            }
            level++;
        }
        return level;
    }
    
};