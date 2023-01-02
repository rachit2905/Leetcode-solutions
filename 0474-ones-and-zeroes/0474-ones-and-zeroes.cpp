class Solution {
public:
    int findMaxForm(vector<string>& str, int m, int n) {
        int dp[m+1][n+1];
        memset(dp,0,sizeof(dp));
        for(auto it:str)
        {
            int ze=count(it.begin(),it.end(),'0');
            int on=it.length()-ze;
            for(int i=m;i>=ze;i--)
            {
                for(int j=n;j>=on;j--)
                {
                    dp[i][j]=max(dp[i][j],1+dp[i-ze][j-on]);
                }
            }
        }
        return dp[m][n];
    }
};