class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int dp[n+1][2];
        memset(dp,-1,sizeof(dp));
        dp[n][0]=dp[n][1]=0;
        for(int i=n-1;i>=0;i--)
        {
          for(int buy=0;buy<=1;buy++)
          {
              int profit=0;
              if(buy==0)profit=max(dp[i+1][0],dp[i+1][1]-prices[i]);
              if(buy==1)profit=max(dp[i+1][1],prices[i]+dp[i+1][0]);
          dp[i][buy]=profit;    
          }
        }
        return dp[0][0];
    }
};