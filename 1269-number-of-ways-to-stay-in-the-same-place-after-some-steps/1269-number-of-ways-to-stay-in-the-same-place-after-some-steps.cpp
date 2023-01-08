class Solution {
public:
     const int MOD = 1000000007;
    const int MAX_LEN = 251;

    vector<vector<int>> dp;

    int recurse(int steps, int arrLen, int pos) {
        if (steps == 0) return pos == 0 ? 1 : 0;
        if (dp[steps][pos] != -1) return dp[steps][pos];
        long long left = 0;
        if (pos > 0) left = recurse(steps-1, arrLen, pos-1) % MOD;
        long long right = 0;
        if (pos < arrLen - 1) right = recurse(steps-1, arrLen, pos+1) % MOD;
        long long stay = recurse(steps-1, arrLen, pos) % MOD;
        return dp[steps][pos] = (left + right + stay) % MOD;
    }
public:
    int numWays(int steps, int arrLen) {
        dp = vector(steps+1, vector(MAX_LEN, -1));
        return recurse(steps, min(arrLen, MAX_LEN), 0) % MOD;
    }
};