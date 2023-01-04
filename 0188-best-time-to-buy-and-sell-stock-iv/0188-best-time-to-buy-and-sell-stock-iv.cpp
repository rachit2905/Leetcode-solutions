class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int dp[prices.size()+1][2*k+1];
        memset(dp,0,sizeof(dp));
        for(int i=prices.size();i>=0;i--)
        {
            for(int j=0;j<=2*k;j++)
            {
                int &ans=dp[i][j];
                if(i==prices.size())
                    ans=0;
               else if(j==0)
                    ans=0;
                else 
                {
                    int ans1=dp[i+1][j];
                    int ans2=0;
                    if(j%2==0)
                        ans2=dp[i+1][j-1]-prices[i];
                    else ans2=prices[i]+dp[i+1][j-1];
                    ans=max(ans1,ans2);
                }
            }
        }
        return dp[0][2*k];
    }
};