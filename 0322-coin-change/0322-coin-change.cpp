class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
       long long int dp[amount+1];
        for(int i=0;i<amount+1;i++)
            dp[i]=INT_MAX;
        dp[0]=0;
        for(int i=0;i<coins.size();i++)
        {
            for(int j=1;j<=amount;j++)
            {
                if(coins[i]<=j)
                dp[j]=min(dp[j],1+dp[j-coins[i]]);
            }
        }
        if(dp[amount]!=INT_MAX)
        return dp[amount];
        else return -1;
    }
};