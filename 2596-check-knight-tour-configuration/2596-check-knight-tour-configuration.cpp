class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        if(grid[0][0]!=0)return 0;
        int co=0,x=0,y=0,n=grid.size(),co1=0;
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<n;j++)
//             {
//                 if(grid[i][j]==0)
//                 {
//                     x=i,y=j;co1=1;
//                     break;
//                 }
                
//             }
//             if(co1)break;
//         }
        //vector<vector<int>>vis(n,vector<int>(n,0));
        //vis[x][y]=1;
        vector<pair<int,int>>v2;
        v2.push_back({2,1});
        v2.push_back({2,-1});
        v2.push_back({-2,-1});
          v2.push_back({-2,1});
          v2.push_back({1,-2});
          v2.push_back({-1,-2});
          v2.push_back({1,2});
           v2.push_back({-1,2});co1=0;
        while(co<(n*n)-1)
        {
            co1=0;
           for(auto it:v2)
           {
               if(x+it.first<n && x+it.first>=0 && y+it.second<n && y+it.second>=0)
               {
                   if(grid[x+it.first][y+it.second]==co+1)
                   {
                       
                       co1=1;
                       x=x+it.first;y=y+it.second;//vis[x][y]=1;
                       break;
                   }
               }
               if(co1)break;
           }
            if(!co1)return 0;
            co++;
        }
        return 1;
    }
};