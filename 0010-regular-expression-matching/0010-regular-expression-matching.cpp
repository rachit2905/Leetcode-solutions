class Solution {
public:
bool isMatch(string s, string p) {
    int m = s.size();
    int n = p.size();
    
    // Create a table of size (m+1) x (n+1) to store the results of subproblems
    bool dp[m+1][n+1];
    memset(dp, false, sizeof(dp));
    
    // Base case: an empty pattern matches an empty string
    dp[0][0] = true;
    
    // Fill in the first row
    for (int j = 1; j <= n; j++) {
        if (p[j-1] == '*') {
            dp[0][j] = dp[0][j-2];
        }
    }
    
    // Fill in the rest of the table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i-1] == p[j-1] || p[j-1] == '.') {
                dp[i][j] = dp[i-1][j-1];
            } else if (p[j-1] == '*') {
                dp[i][j] = dp[i][j-2] || (dp[i-1][j] && (s[i-1] == p[j-2] || p[j-2] == '.'));
            } else {
                dp[i][j] = false;
            }
        }
    }
    
    return dp[m][n];
}

    
};