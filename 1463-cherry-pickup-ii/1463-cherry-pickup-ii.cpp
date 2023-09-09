class Solution {
public:
    int help(vector<vector<int>>& grid,int i,int j1,int j2,vector<vector<vector<int>>>&dp,int m,int n)
    {
        if(j1<0 || j2<0 || j1>=n || j2>=n  )return INT_MIN;
        //if(i>=m)return 0;
        if(i==m-1)
        {
            if(j1==j2)return grid[i][j1];
            else return grid[i][j1]+grid[i][j2];
        }
        if(dp[i][j1][j2]!=-1)return dp[i][j1][j2];int mx=INT_MIN;
        for(int co=-1;co<=1;co++)
        {
            int value=0;
            for(int co1=-1;co1<=1;co1++)
            {
                
            value=0;
                if(j1==j2)
                {
                    value=grid[i][j2];
                }
                else
                    value=grid[i][j1]+grid[i][j2];
                value+=help(grid,i+1,j1+co,j2+co1,dp,m,n); mx=max(mx,value);    
            }
           
        }
        return dp[i][j1][j2]=mx;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(n,-1)));
       return  help(grid,0,0,n-1,dp,m,n);
        
    }
};