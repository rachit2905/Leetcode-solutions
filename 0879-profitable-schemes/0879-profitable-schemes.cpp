class Solution {
public:
    
    int profitableSchemes(int n, int minProfit, vector<int>& groups, vector<int>& profits) {
        int dp[profits.size()+1][n+1][minProfit+1];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<=n;i++)
        {
            dp[profits.size()][i][minProfit]=1;
        }
        for(int i=profits.size()-1;i>=0;i--)
        {
            for(int j=0;j<=n;j++)
            {
                for(int k=minProfit;k>=0;k--)
                {
                    long long ans=dp[i+1][j][k];
                    if(j>=groups[i])ans+=dp[i+1][j-groups[i]][min(minProfit,k+profits[i])];
                    dp[i][j][k]=(int)ans%(int)(1e9+7);
                }
            }
        }
        return dp[0][n][0];
    }
};