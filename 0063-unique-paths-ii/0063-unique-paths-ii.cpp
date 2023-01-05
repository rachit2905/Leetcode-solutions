class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int a=obstacleGrid.size();
        int b=obstacleGrid[0].size();
        int dp[a][b];
          memset(dp,0,sizeof(dp));
        if(obstacleGrid[0][0]==1)return 0;
        dp[0][0]=1;
        for(int i=0;i<a;i++)
        {
            for(int j=0;j<b;j++)
            {
                if(obstacleGrid[i][j]==0)
                {
                if(i>0 && obstacleGrid[i-1][j]==0)
                dp[i][j]+=dp[i-1][j];
                if(j>0 && obstacleGrid[i][j-1]==0)
                dp[i][j]+=dp[i][j-1];
                }
                
                
            }
        }
        
        return dp[a-1][b-1];
        
    }
};