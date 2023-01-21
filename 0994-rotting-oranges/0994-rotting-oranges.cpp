class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
       int ans=0,co=0,m=grid.size(),n=grid[0].size();
        queue<pair<int,int>>q1;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                    co++;
                else if(grid[i][j]==2)
                {
                    q1.push({i,j});
                }
            }
        }
        int dir[]={0,0,1,-1};
        int diry[]={1,-1,0,0};
        while(!q1.empty())
        {
            int sz=q1.size();
            for(int i=0;i<sz;i++)
            {
                auto it=q1.front();
                q1.pop();
                for(int i=0;i<4;i++)
                {
                    int x=it.first+dir[i];
                    int y=it.second+diry[i];
                    if(x<0 || x>=m || y<0 || y>=n || grid[x][y]==2 || grid[x][y]==0) 
                        continue;
                    else
                    {
                        q1.push({x,y});
                        grid[x][y]=2;
                        co--;
                    }
                }
            }
            ans++;
        }
       if(co)return -1;
        else return max(ans-1,0);
    
    }
};