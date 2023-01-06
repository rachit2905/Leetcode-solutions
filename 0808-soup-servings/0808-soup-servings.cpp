class Solution {
    double f(vector<vector<double>> &dp, int A, int B){
        if(!A && !B)
            return 0.5;
        if(!A || !B)
            return !A ? 1.0 : 0;
        if(dp[A][B] != -1)
            return dp[A][B];
        double ans = 0;
        for(int i = 25; i <= 100; i += 25){
            ans += 0.25 * f(dp, max(0, A - i), max(0, B - 100 + i));
        }
        return dp[A][B] = ans;
    }
public:
    double soupServings(int n) {
        if(n == 0)
            return 0.5;
        if(n > 4800)
            return 1.0;
        vector<vector<double>> dp(n + 1, vector<double>(n + 1, -1));
        f(dp, n, n);
        return dp[n][n];
    }
};