class Solution {
public:
      int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int&& n = piles.size();
        vector dp(k + 1, 0);
        vector prev(k + 1, 0);
        for (int i = 1; i <= n; i++) 
        {
            for (int c = 0; c <= k; c++) {
                int sum = 0;
                int min_i=min((int)piles[i - 1].size(), c);
                for (int j = 0; j <= min_i; j++) {
                    if (j > 0) 
                        sum += piles[i - 1][j - 1];
                    dp[c] = max(dp[c], prev[c - j] + sum);
                }
            }
            prev=dp;
        }
        return dp[k];
      }
};