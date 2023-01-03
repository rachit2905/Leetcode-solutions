class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
            int last = days.back(), dp[last + 1];
        dp[0] = 0;
        for (int i = 1, j = 0; i <= last; i++) {
            if (i == days[j]) {
                // moving j to the next number
                j++;
                // dp[i] must be the min of
                dp[i] = min({
                    // a daily ticket plus previous costs
                    costs[0] + dp[i - 1],
                    // a weekly ticket plus previous costs
                    costs[1] + dp[i - min(i, 7)],
                    // a monthly ticket plus previous costs
                    costs[2] + dp[i - min(i, 30)],
                });
            }
            else {
                // alternatively we keep progressing with the last recorded value
                dp[i] = dp[i - 1];
            }
        }
        return dp[last];
    }

};